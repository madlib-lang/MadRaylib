#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__triangle__draw(madlib__record__Record_t *v1, madlib__record__Record_t *v2, madlib__record__Record_t *v3,
                               madlib__record__Record_t *color) {
  DrawTriangle(madraylib__math__vector2ToRaylib(v1), madraylib__math__vector2ToRaylib(v2),
               madraylib__math__vector2ToRaylib(v3), madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawLines(madlib__record__Record_t *v1, madlib__record__Record_t *v2, madlib__record__Record_t *v3,
                               madlib__record__Record_t *color) {
  DrawTriangleLines(madraylib__math__vector2ToRaylib(v1), madraylib__math__vector2ToRaylib(v2),
               madraylib__math__vector2ToRaylib(v3), madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawTriangleFan(madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  DrawTriangleFan(madraylib__math__toPoints(madlibPoints), madlibPoints->length, madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawTriangleStrip(madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  DrawTriangleStrip(madraylib__math__toPoints(madlibPoints), madlibPoints->length, madraylib__color__toRaylib(color));
}

void madraylib__triangle__drawTriangleStrip3D(madlib__array__Array_t *madlibPoints, madlib__record__Record_t *color) {
  Vector3 *points = madraylib__math__to3DPoints(madlibPoints);
  DrawTriangleStrip3D(points, madlibPoints->length, madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif
