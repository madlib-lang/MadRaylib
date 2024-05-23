#ifndef GC_THREADS
#define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./texture.hpp"
#include "array.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__shader__beginShaderMode(Shader *shader) {
  BeginShaderMode(*shader);
}

void madraylib__shader__endShaderMode() { EndShaderMode(); }

Shader *madraylib__shader__load(char *vsFileName, char *fsFileName) {
  Shader *s = (Shader *)GC_MALLOC(sizeof(Shader));
  *s = LoadShader(vsFileName, fsFileName);
  return s;
}

Shader *madraylib__shader__loadFromMemory(char *vsCode, char *fsCode) {
  Shader *s = (Shader *)GC_MALLOC(sizeof(Shader));
  *s = LoadShaderFromMemory(vsCode, fsCode);
  return s;
}

void madraylib__shader__unloadShader(Shader *shader) { UnloadShader(*shader); }

int32_t madraylib__shader__getShaderLocation(Shader *shader,
                                             char *uniformName) {
  return GetShaderLocation(*shader, uniformName);
}

const void *madraylib__shader__transformShaderValue(void *value,
                                                    int32_t uniformType) {
  if (uniformType == SHADER_UNIFORM_FLOAT) {
    float *_value = (float *)GC_MALLOC_ATOMIC(sizeof(float));
    *_value = (float)unboxDouble((double *)value);
    return _value;
  } else if (uniformType == SHADER_UNIFORM_VEC2) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 2);
    floats[0] = (float)unboxDouble((double *)_value->fields[0].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[1].value);
    return floats;
  } else if (uniformType == SHADER_UNIFORM_VEC3) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 3);
    floats[0] = (float)unboxDouble((double *)_value->fields[0].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[1].value);
    floats[2] = (float)unboxDouble((double *)_value->fields[2].value);
    return floats;
  } else if (uniformType == SHADER_UNIFORM_VEC4) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 4);
    floats[0] = (float)unboxDouble((double *)_value->fields[1].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[2].value);
    floats[2] = (float)unboxDouble((double *)_value->fields[3].value);
    floats[3] = (float)unboxDouble((double *)_value->fields[0].value);
    return floats;
  } else if (uniformType == SHADER_UNIFORM_INT) {
    int32_t *_value = (int32_t *)GC_MALLOC_ATOMIC(sizeof(int32_t));
    *_value = (int32_t)(int64_t)value;
    return _value;
  }

  return NULL;
}

void madraylib__shader__setShaderValue(Shader *s, int32_t locationIndex,
                                       void *value, int32_t uniformType) {
  SetShaderValue(*s, locationIndex,
                 madraylib__shader__transformShaderValue(value, uniformType),
                 uniformType);
}

void madraylib__shader__setShaderValues(Shader *s, int32_t locationIndex,
                                        madlib__array__Array_t *values,
                                        int32_t uniformType) {
  if (uniformType == SHADER_UNIFORM_VEC2) {
    float *transformed = (float *)GC_MALLOC(sizeof(float) * values->length * 2);
    for (int i = 0; i < values->length * 2; i += 2) {
      float *floats = (float *)madraylib__shader__transformShaderValue(
          values->items[i / 2], uniformType);
      transformed[i] = floats[0];
      transformed[i + 1] = floats[1];
    }
    SetShaderValueV(*s, locationIndex, transformed, uniformType,
                    values->length);
  } else if (uniformType == SHADER_UNIFORM_VEC3) {
    float *transformed = (float *)GC_MALLOC(sizeof(float) * values->length * 3);
    for (int i = 0; i < values->length * 3; i += 3) {
      float *floats = (float *)madraylib__shader__transformShaderValue(
          values->items[i / 3], uniformType);
      transformed[i] = floats[0];
      transformed[i + 1] = floats[1];
      transformed[i + 2] = floats[2];
    }
    SetShaderValueV(*s, locationIndex, transformed, uniformType,
                    values->length);
  } else if (uniformType == SHADER_UNIFORM_VEC4) {
    float *transformed = (float *)GC_MALLOC(sizeof(float) * values->length * 4);
    for (int i = 0; i < values->length * 4; i += 4) {
      float *floats = (float *)madraylib__shader__transformShaderValue(
          values->items[i / 4], uniformType);
      transformed[i] = floats[0];
      transformed[i + 1] = floats[1];
      transformed[i + 2] = floats[2];
      transformed[i + 3] = floats[3];
    }
    SetShaderValueV(*s, locationIndex, transformed, uniformType,
                    values->length);
  } else if (uniformType == SHADER_UNIFORM_FLOAT) {
    float *transformed = (float *)GC_MALLOC(sizeof(float) * values->length);
    for (int i = 0; i < values->length; i++) {
      float *floats = (float *)madraylib__shader__transformShaderValue(
          values->items[i], uniformType);
      transformed[i] = floats[0];
    }
    SetShaderValueV(*s, locationIndex, transformed, uniformType,
                    values->length);
  } else {
    const void **transformed =
        (const void **)GC_MALLOC(sizeof(void *) * values->length);
    for (int i = 0; i < values->length; i++) {
      ((void **)transformed)[i] =
          *((void **)madraylib__shader__transformShaderValue(values->items[i],
                                                             uniformType));
    }
    SetShaderValueV(*s, locationIndex, transformed, uniformType,
                    values->length);
  }
}

void madraylib__shader__setShaderValueTexture(
    Shader *s, int32_t locationIndex, madlib__record__Record_t *texture) {
  SetShaderValueTexture(*s, locationIndex,
                        madraylib__texture__toRaylib(texture));
}

#ifdef __cplusplus
}
#endif
