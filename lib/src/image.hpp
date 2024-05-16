#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "array.hpp"
#include "bytearray.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Image madraylib__image__toRaylib(madlib__record__Record_t *image);

madlib__record__Record_t *madraylib__image__fromRaylib(Image *image);

#ifdef __cplusplus
}
#endif
