#include <raylib.h>
#include <stdint.h>

#include "array.hpp"
#include "color.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__texture__load(char *c) {
  Texture2D texture = LoadTexture(c);

  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(sizeof(madlib__record__Field_t*) * 5);
  madlib__record__Record_t *result = (madlib__record__Record_t*) GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 5;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[0]->name = "format";
  fields[0]->value = (void*) texture.format;

  fields[1] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[1]->name = "height";
  fields[1]->value = (void*) texture.height;

  fields[2] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[2]->name = "id";
  fields[2]->value = (void*) texture.id;

  fields[3] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[3]->name = "mipmaps";
  fields[3]->value = (void*) texture.mipmaps;

  fields[4] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[4]->name = "width";
  fields[4]->value = (void*) texture.width;

  return result;
}

#ifdef __cplusplus
}
#endif
