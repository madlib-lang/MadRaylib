#include "gc.h"
#include <raylib.h>
#include <stdint.h>
#include "record.hpp"
#include "number.hpp"
#include "color.hpp"


#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__rectangle__fromRaylib(Rectangle *rect) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(sizeof(madlib__record__Field_t*) * 4);
  madlib__record__Record_t *result = (madlib__record__Record_t*) GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[0]->name = "height";
  fields[0]->value = (void*) boxDouble(rect->height);

  fields[1] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[1]->name = "width";
  fields[1]->value = (void*) boxDouble(rect->width);

  fields[2] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[2]->name = "x";
  fields[2]->value = (void*) boxDouble(rect->x);

  fields[3] = (madlib__record__Field_t*) GC_MALLOC(sizeof(madlib__record__Field_t));
  fields[3]->name = "y";
  fields[3]->value = (void*) boxDouble(rect->y);

  return result;
}


Rectangle *madraylib__rectangle__toRaylib(madlib__record__Record_t *rectangle) {
  Rectangle *result = (Rectangle *) GC_MALLOC(sizeof(Rectangle));
  result->height = unboxDouble((double*)rectangle->fields[0]->value);
  result->width = unboxDouble((double*)rectangle->fields[1]->value);
  result->x = unboxDouble((double*)rectangle->fields[2]->value);
  result->y = unboxDouble((double*)rectangle->fields[3]->value);
  return result;
}


void madraylib__rectangle__drawRectangleRec(madlib__record__Record_t *rectangle, madlib__record__Record_t *color) {
  Color *c = madraylib__color__toRaylib(color);
  Rectangle *r = madraylib__rectangle__toRaylib(rectangle);
  DrawRectangleRec(*r, *c);
}


#ifdef __cplusplus
}
#endif