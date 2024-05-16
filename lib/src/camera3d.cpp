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

madlib__record__Record_t *madraylib__camera3d__fromRaylib(Camera3D *camera) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 5);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 5;
  result->fields = fields;

  fields[0] = {
    .name = "fovy",
    .value = boxDouble(camera->fovy),
  };
  fields[1] = {
    .name = "position",
    .value = madraylib__math__vector3FromRaylib(&camera->position),
  };
  fields[2] = {
    .name = "projection",
    .value = (void*) camera->projection,
  };
  fields[3] = {
    .name = "target",
    .value = madraylib__math__vector3FromRaylib(&camera->target),
  };
  fields[4] = {
    .name = "up",
    .value = madraylib__math__vector3FromRaylib(&camera->up),
  };

  return result;
}

Camera3D madraylib__camera3d__toRaylib(madlib__record__Record_t *camera) {
  return {
    .fovy = (float) unboxDouble((void*) camera->fields[0].value),
    .position = madraylib__math__vector3ToRaylib((madlib__record__Record_t*) camera->fields[1].value),
    .projection = (int32_t) (int64_t) ((madlib__record__Record_t*) camera->fields[2].value),
    .target = madraylib__math__vector3ToRaylib((madlib__record__Record_t*) camera->fields[3].value),
    .up = madraylib__math__vector3ToRaylib((madlib__record__Record_t*) camera->fields[4].value),
  };
}

void madraylib__camera3d__begin3DMode(madlib__record__Record_t *camera) {
  BeginMode3D(madraylib__camera3d__toRaylib(camera));
}

void madraylib__camera3d__endMode3D() {
  EndMode3D();
}

#ifdef __cplusplus
}
#endif