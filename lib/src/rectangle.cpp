#include "./rectangle.hpp"

#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__rectangle__fromRaylib(Rectangle *rect) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(
      sizeof(madlib__record__Field_t *) * 4);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[0]->name = "height";
  fields[0]->value = (void *)boxDouble(rect->height);

  fields[1] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[1]->name = "width";
  fields[1]->value = (void *)boxDouble(rect->width);

  fields[2] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[2]->name = "x";
  fields[2]->value = (void *)boxDouble(rect->x);

  fields[3] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[3]->name = "y";
  fields[3]->value = (void *)boxDouble(rect->y);

  return result;
}

Rectangle madraylib__rectangle__toRaylib(madlib__record__Record_t *rectangle) {
  return {
      .x = (float)unboxDouble((double *)rectangle->fields[2]->value),
      .y = (float)unboxDouble((double *)rectangle->fields[3]->value),
      .width = (float)unboxDouble((double *)rectangle->fields[1]->value),
      .height = (float)unboxDouble((double *)rectangle->fields[0]->value),
  };
}

void madraylib__rectangle__draw(double x, double y, double width, double height,
                                madlib__record__Record_t *color) {
  DrawRectangle(x, y, width, height, madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawV(madlib__record__Record_t *position,
                                 madlib__record__Record_t *size,
                                 madlib__record__Record_t *color) {
  DrawRectangleV(madraylib__math__vector2ToRaylib(position),
                 madraylib__math__vector2ToRaylib(size),
                 madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawRec(madlib__record__Record_t *rectangle,
                                            madlib__record__Record_t *color) {
  DrawRectangleRec(madraylib__rectangle__toRaylib(rectangle),
                   madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawPro(madlib__record__Record_t *rec,
                                   madlib__record__Record_t *origin,
                                   double rotation,
                                   madlib__record__Record_t *color) {
  DrawRectanglePro(madraylib__rectangle__toRaylib(rec),
                   madraylib__math__vector2ToRaylib(origin), rotation,
                   madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawLines(double x, double y, double width, double height, madlib__record__Record_t *color) {
    DrawRectangleLines(x, y, width, height, madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawLinesEx(madlib__record__Record_t *rectangle, double thickness, madlib__record__Record_t *color) {
    DrawRectangleLinesEx(madraylib__rectangle__toRaylib(rectangle), thickness, madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawRounded(madlib__record__Record_t *rectangle, double roundness, int32_t segments, madlib__record__Record_t *color) {
    DrawRectangleRounded(madraylib__rectangle__toRaylib(rectangle), roundness, segments, madraylib__color__toRaylib(color));
}

void madraylib__rectangle__drawRoundedLines(madlib__record__Record_t *rectangle, double roundness, int32_t segments, double thickness, madlib__record__Record_t *color) {
    DrawRectangleRoundedLines(madraylib__rectangle__toRaylib(rectangle), roundness, segments, thickness, madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif