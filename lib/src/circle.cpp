#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__circle__draw(double centerX, double centerY, double radius,
                             madlib__record__Record_t *color) {
  DrawCircle(centerX, centerY, radius, madraylib__color__toRaylib(color));
}

void madraylib__circle__drawSector(madlib__record__Record_t *center,
                                   double radius, double startAngle,
                                   double endAngle, int32_t segments,
                                   madlib__record__Record_t *color) {
  DrawCircleSector(madraylib__math__vector2ToRaylib(center), radius, startAngle,
                   endAngle, segments, madraylib__color__toRaylib(color));
}

void madraylib__circle__drawGradient(double centerX, double centerY,
                                     double radius,
                                     madlib__record__Record_t *color1,
                                     madlib__record__Record_t *color2) {
  DrawCircleGradient(centerX, centerY, radius,
                     madraylib__color__toRaylib(color1),
                     madraylib__color__toRaylib(color2));
}

void madraylib__circle__drawV(madlib__record__Record_t *center, double radius,
                              madlib__record__Record_t *color) {
  DrawCircleV(madraylib__math__vector2ToRaylib(center), radius,
              madraylib__color__toRaylib(color));
}

void madraylib__circle__drawLines(double centerX, double centerY, double radius,
                                  madlib__record__Record_t *color) {
  DrawCircleLines(centerX, centerY, radius, madraylib__color__toRaylib(color));
}

void madraylib__circle__drawLinesV(madlib__record__Record_t *center,
                                   double radius,
                                   madlib__record__Record_t *color) {
  DrawCircleLinesV(madraylib__math__vector2ToRaylib(center), radius,
                   madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif