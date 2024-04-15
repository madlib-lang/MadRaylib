#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif


void madraylib__triangle__drawTriangleStrip(
    madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  Vector2 *points = madraylib__math__toPoints(madlibPoints);
  DrawTriangleStrip(points, madlibPoints->length,
                    madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawTriangleStrip3D(
    madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  Vector3 *points = madraylib__math__to3DPoints(madlibPoints);
  DrawTriangleStrip3D(points, madlibPoints->length,
                      madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif
