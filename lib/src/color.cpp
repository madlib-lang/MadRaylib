#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include "color.hpp"

#include <stdint.h>

#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__color__fromRaylib(Color *color) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(
      sizeof(madlib__record__Field_t) * 4);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = {
    .name = "a",
    .value = (void*) color->a,
  };
  fields[1] = {
    .name = "b",
    .value = (void*) color->b,
  };
  fields[2] = {
    .name = "g",
    .value = (void*) color->g,
  };
  fields[3] = {
    .name = "r",
    .value = (void*) color->r,
  };

  return result;
}

Color madraylib__color__toRaylib(madlib__record__Record_t *color) {
  return {
      .r = (unsigned char)((int64_t)color->fields[3].value),
      .g = (unsigned char)((int64_t)color->fields[2].value),
      .b = (unsigned char)((int64_t)color->fields[1].value),
      .a = (unsigned char)((int64_t)color->fields[0].value),
  };
}

#ifdef __cplusplus
}
#endif