#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include "gc.h"
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__cylinder__draw(madlib__record__Record_t *position, double radiusTop, double radiusBottom, double height, int32_t slices, madlib__record__Record_t *color) {
  DrawCylinder(madraylib__math__vector3ToRaylib(position), radiusTop, radiusBottom, height, slices, madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif
