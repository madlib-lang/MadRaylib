#include "./math.hpp"

#include <stdint.h>

#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Vector2 madraylib__math__vector2ToRaylib(madlib__record__Record_t *vec2) {
  return {
      .x = (float)unboxDouble((double *)vec2->fields[0].value),
      .y = (float)unboxDouble((double *)vec2->fields[1].value),
  };
}

Vector3 madraylib__math__vector3ToRaylib(madlib__record__Record_t *vec3) {
  return {
      .x = (float)unboxDouble((double *)vec3->fields[0].value),
      .y = (float)unboxDouble((double *)vec3->fields[1].value),
      .z = (float)unboxDouble((double *)vec3->fields[2].value),
  };
}

Vector4 madraylib__math__vector4ToRaylib(madlib__record__Record_t *vec4) {
  return {
      .x = (float)unboxDouble((double *)vec4->fields[1].value),
      .y = (float)unboxDouble((double *)vec4->fields[2].value),
      .z = (float)unboxDouble((double *)vec4->fields[3].value),
      .w = (float)unboxDouble((double *)vec4->fields[0].value),
  };
}

madlib__record__Record_t *madraylib__math__vector2FromRaylib(Vector2 *vec2) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 2);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 2;
  result->fields = fields;

  fields[0] = {
      .name = "x",
      .value = (void *)boxDouble(vec2->x),
  };

  fields[1] = {
      .name = "y",
      .value = (void *)boxDouble(vec2->y),
  };

  return result;
}

madlib__record__Record_t *madraylib__math__vector3FromRaylib(Vector3 *vec3) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 3);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 3;
  result->fields = fields;

  fields[0] = {
      .name = "x",
      .value = (void *)boxDouble(vec3->x),
  };
  fields[1] = {
      .name = "y",
      .value = (void *)boxDouble(vec3->y),
  };
  fields[2] = {
      .name = "z",
      .value = (void *)boxDouble(vec3->z),
  };

  return result;
}

madlib__record__Record_t *madraylib__math__vector4FromRaylib(Vector4 *vec4) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 4);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = {
      .name = "w",
      .value = (void *)boxDouble(vec4->w),
  };
  fields[1] = {
      .name = "x",
      .value = (void *)boxDouble(vec4->x),
  };
  fields[2] = {
      .name = "y",
      .value = (void *)boxDouble(vec4->y),
  };
  fields[3] = {
      .name = "z",
      .value = (void *)boxDouble(vec4->z),
  };

  return result;
}

Vector2 *madraylib__math__toPoints(madlib__array__Array_t *madlibPoints) {
  Vector2 *points = (Vector2 *)GC_MALLOC_ATOMIC(sizeof(Vector2) * madlibPoints->length);

  for (int i = 0; i < madlibPoints->length; i++) {
    auto madlibPoint = (((madlib__record__Record_t **)madlibPoints->items)[i]);
    points[i] = {(float)unboxDouble((double *)madlibPoint->fields[0].value),
                 (float)unboxDouble((double *)madlibPoint->fields[1].value)};
  }

  return points;
}

Vector3 *madraylib__math__to3DPoints(madlib__array__Array_t *madlibPoints) {
  Vector3 *points = (Vector3 *)GC_MALLOC_ATOMIC(sizeof(Vector3) * madlibPoints->length);

  for (int i = 0; i < madlibPoints->length; i++) {
    auto madlibPoint = (((madlib__record__Record_t **)madlibPoints->items)[i]);
    points[i] = {(float)unboxDouble((double *)madlibPoint->fields[0].value),
                 (float)unboxDouble((double *)madlibPoint->fields[1].value),
                 (float)unboxDouble((double *)madlibPoint->fields[2].value)};
  }

  return points;
}

#ifdef __cplusplus
}
#endif