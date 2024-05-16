#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__line__draw(double startX, double startY, double endX, double endY, madlib__record__Record_t *color) {
  DrawLine(startX, startY, endX, endY, madraylib__color__toRaylib(color));
}

void madraylib__line__drawV(madlib__record__Record_t *start, madlib__record__Record_t *end,
                            madlib__record__Record_t *color) {
  DrawLineV(madraylib__math__vector2ToRaylib(start), madraylib__math__vector2ToRaylib(end),
            madraylib__color__toRaylib(color));
}

void madraylib__line__drawEx(madlib__record__Record_t *start, madlib__record__Record_t *end, double thickness,
                             madlib__record__Record_t *color) {
  DrawLineEx(madraylib__math__vector2ToRaylib(start), madraylib__math__vector2ToRaylib(end), thickness,
             madraylib__color__toRaylib(color));
}

void madraylib__line__drawStrip(madlib__array__Array_t *points, madlib__record__Record_t *color) {
  DrawLineStrip(madraylib__math__toPoints(points), points->length, madraylib__color__toRaylib(color));
}

void madraylib__line__drawBezier(madlib__record__Record_t *start, madlib__record__Record_t *end, double thickness,
                                 madlib__record__Record_t *color) {
  DrawLineBezier(madraylib__math__vector2ToRaylib(start), madraylib__math__vector2ToRaylib(end), thickness,
                 madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif