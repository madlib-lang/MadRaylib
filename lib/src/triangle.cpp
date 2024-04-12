#include <raylib.h>
#include <stdint.h>

#include "array.hpp"
#include "color.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// TODO: idea, convert madlib Array Vector2 to an internal Vector2* and expose
// that to madlib land as an opaque type to avoid repetitive conversion. Maybe
// we call it "Points"

Vector2 *madraylib__array__toPoints(madlib__array__Array_t *madlibPoints) {
  Vector2 *points =
      (Vector2 *)GC_MALLOC_ATOMIC(sizeof(Vector2) * madlibPoints->length);

  for (int i = 0; i < madlibPoints->length; i++) {
    auto madlibPoint = (((madlib__record__Record_t **)madlibPoints->items)[i]);
    points[i] = {(float)unboxDouble((double *)madlibPoint->fields[0]->value),
                 (float)unboxDouble((double *)madlibPoint->fields[1]->value)};
  }

  return points;
}

Vector3 *madraylib__array__to3DPoints(madlib__array__Array_t *madlibPoints) {
  Vector3 *points =
      (Vector3 *)GC_MALLOC_ATOMIC(sizeof(Vector3) * madlibPoints->length);

  for (int i = 0; i < madlibPoints->length; i++) {
    auto madlibPoint = (((madlib__record__Record_t **)madlibPoints->items)[i]);
    points[i] = {(float)unboxDouble((double *)madlibPoint->fields[0]->value),
                 (float)unboxDouble((double *)madlibPoint->fields[1]->value),
                 (float)unboxDouble((double *)madlibPoint->fields[2]->value)};
  }

  return points;
}

// RLAPI void DrawTriangleStrip(Vector2 *points, int pointCount, Color color);
void madraylib__triangle__drawTriangleStrip(
    madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  Vector2 *points = madraylib__array__toPoints(madlibPoints);
  DrawTriangleStrip(points, madlibPoints->length,
                    madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawTriangleStrip3D(
    madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  Vector3 *points = madraylib__array__to3DPoints(madlibPoints);
  DrawTriangleStrip3D(points, madlibPoints->length,
                      madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif
