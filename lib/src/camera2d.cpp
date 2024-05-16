#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./math.hpp"
#include "record.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__camera2d__fromRaylib(Camera2D *camera) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 4);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 4;
  result->fields = fields;

  fields[0] = {
    .name = "offset",
    .value = madraylib__math__vector2FromRaylib(&camera->offset),
  };
  fields[1] = {
    .name = "rotation",
    .value = boxDouble((double)camera->rotation),
  };
  fields[2] = {
    .name = "target",
    .value = madraylib__math__vector2FromRaylib(&camera->target),
  };
  fields[3] = {
    .name = "zoom",
    .value = boxDouble((double)camera->zoom),
  };

  return result;
}

Camera2D madraylib__camera2d__toRaylib(madlib__record__Record_t *camera) {
  return {
    .offset = madraylib__math__vector2ToRaylib((madlib__record__Record_t*) camera->fields[0].value),
    .rotation = (float) unboxDouble((void*) camera->fields[1].value),
    .target = madraylib__math__vector2ToRaylib((madlib__record__Record_t*) camera->fields[2].value),
    .zoom = (float) unboxDouble((void*) camera->fields[3].value),
  };
}

void madraylib__camera2d__begin2DMode(madlib__record__Record_t *camera) {
  BeginMode2D(madraylib__camera2d__toRaylib(camera));
}

void madraylib__camera2d__endMode2D() {
  EndMode2D();
}

madlib__record__Record_t *madraylib__camera2d__getScreenToWorld2D(madlib__record__Record_t *position, madlib__record__Record_t *camera) {
  Vector2 worldPosition = GetScreenToWorld2D(madraylib__math__vector2ToRaylib(position), madraylib__camera2d__toRaylib(camera));
  return madraylib__math__vector2FromRaylib(&worldPosition);
}

madlib__record__Record_t *madraylib__camera2d__getWorldToScreen2D(madlib__record__Record_t *position, madlib__record__Record_t *camera) {
  Vector2 screenPosition = GetWorldToScreen2D(madraylib__math__vector2ToRaylib(position), madraylib__camera2d__toRaylib(camera));
  return madraylib__math__vector2FromRaylib(&screenPosition);
}

#ifdef __cplusplus
}
#endif