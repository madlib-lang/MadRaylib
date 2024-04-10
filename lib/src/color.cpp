#include "gc.h"
#include <stdint.h>
#include "number.hpp"
#include "color.hpp"


#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__color__fromRaylib(Color *color) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(sizeof(madlib__record__Field_t*) * 4);
  madlib__record__Record_t *result = (madlib__record__Record_t*) GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[0]->name = "a";
  fields[0]->value = (void*) color->a;

  fields[1] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[1]->name = "b";
  fields[1]->value = (void*) color->b;

  fields[2] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[2]->name = "g";
  fields[2]->value = (void*) color->g;

  fields[3] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[3]->name = "r";
  fields[3]->value = (void*) color->r;

  return result;
}


Color *madraylib__color__toRaylib(madlib__record__Record_t *color) {
  Color *result = (Color *) GC_MALLOC(sizeof(Color));
  result->a = (unsigned char) ((int64_t) color->fields[0]->value);
  result->b = (unsigned char) ((int64_t) color->fields[1]->value);
  result->g = (unsigned char) ((int64_t) color->fields[2]->value);
  result->r = (unsigned char) ((int64_t) color->fields[3]->value);
  return result;
}


#ifdef __cplusplus
}
#endif