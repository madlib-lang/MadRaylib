#include "./math.hpp"

#include <stdint.h>

#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Vector2 madraylib__math__vector2ToRaylib(madlib__record__Record_t *vec2) {
  return {
      .x = (float)unboxDouble((double *)vec2->fields[0]->value),
      .y = (float)unboxDouble((double *)vec2->fields[1]->value),
  };
}

Vector3 madraylib__math__vector3ToRaylib(madlib__record__Record_t *vec3) {
  return {
      .x = (float)unboxDouble((double *)vec3->fields[0]->value),
      .y = (float)unboxDouble((double *)vec3->fields[1]->value),
      .z = (float)unboxDouble((double *)vec3->fields[2]->value),
  };
}

Vector4 madraylib__math__vector4ToRaylib(madlib__record__Record_t *vec4) {
  return {
      .x = (float)unboxDouble((double *)vec4->fields[1]->value),
      .y = (float)unboxDouble((double *)vec4->fields[2]->value),
      .z = (float)unboxDouble((double *)vec4->fields[3]->value),
      .w = (float)unboxDouble((double *)vec4->fields[0]->value),
  };
}

madlib__record__Record_t *madraylib__math__vector2FromRaylib(Vector2 *vec2) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(
      sizeof(madlib__record__Field_t *) * 2);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 2;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[0]->name = "x";
  fields[0]->value = (void *)boxDouble(vec2->x);

  fields[1] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[1]->name = "y";
  fields[1]->value = (void *)boxDouble(vec2->y);

  return result;
}

madlib__record__Record_t *madraylib__math__vector3FromRaylib(Vector3 *vec3) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(
      sizeof(madlib__record__Field_t *) * 3);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 3;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[0]->name = "x";
  fields[0]->value = (void *)boxDouble(vec3->x);

  fields[1] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[1]->name = "y";
  fields[1]->value = (void *)boxDouble(vec3->y);

  fields[2] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[2]->name = "z";
  fields[2]->value = (void *)boxDouble(vec3->z);

  return result;
}

madlib__record__Record_t *madraylib__math__vector4FromRaylib(Vector4 *vec4) {
  madlib__record__Field_t **fields = (madlib__record__Field_t **)GC_MALLOC(
      sizeof(madlib__record__Field_t *) * 4);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[0]->name = "w";
  fields[0]->value = (void *)boxDouble(vec4->w);

  fields[1] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[1]->name = "x";
  fields[1]->value = (void *)boxDouble(vec4->x);

  fields[2] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[2]->name = "y";
  fields[2]->value = (void *)boxDouble(vec4->y);

  fields[3] = (madlib__record__Field_t *)GC_MALLOC_ATOMIC(
      sizeof(madlib__record__Field_t));
  fields[3]->name = "z";
  fields[3]->value = (void *)boxDouble(vec4->z);

  return result;
}

#ifdef __cplusplus
}
#endif