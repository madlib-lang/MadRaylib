#include <raylib.h>
#include <stdint.h>

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

void madraylib__shader__setShaderLocation(Shader *s, int32_t locationIndex,
                                          void *value, int32_t uniformType) {
  void *transformedValue = value;
  if (uniformType == SHADER_UNIFORM_FLOAT) {
    auto _value = (float *)GC_MALLOC_ATOMIC(sizeof(float));
    *_value = (float)unboxDouble((double *)value);
    transformedValue = _value;
  } else if (uniformType == SHADER_UNIFORM_VEC2) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 2);
    floats[0] = (float)unboxDouble((double *)_value->fields[0].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[1].value);
    transformedValue = floats;
  } else if (uniformType == SHADER_UNIFORM_VEC3) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 3);
    floats[0] = (float)unboxDouble((double *)_value->fields[0].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[1].value);
    floats[2] = (float)unboxDouble((double *)_value->fields[2].value);
    transformedValue = floats;
  } else if (uniformType == SHADER_UNIFORM_VEC4) {
    madlib__record__Record_t *_value = (madlib__record__Record_t *)value;
    float *floats = (float *)GC_MALLOC_ATOMIC(sizeof(float) * 4);
    floats[0] = (float)unboxDouble((double *)_value->fields[1].value);
    floats[1] = (float)unboxDouble((double *)_value->fields[2].value);
    floats[2] = (float)unboxDouble((double *)_value->fields[3].value);
    floats[3] = (float)unboxDouble((double *)_value->fields[0].value);
    transformedValue = floats;
  }

  SetShaderValue(*s, locationIndex, transformedValue, uniformType);
}

#ifdef __cplusplus
}
#endif