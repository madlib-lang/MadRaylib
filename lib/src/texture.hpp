#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "array.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Texture2D madraylib__texture__toRaylib(madlib__record__Record_t *texture);

madlib__record__Record_t *madraylib__texture__fromRaylib(Texture2D *texture);

#ifdef __cplusplus
}
#endif
