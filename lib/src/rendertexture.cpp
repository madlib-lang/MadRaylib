#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "gc.h"
#include "record.hpp"
#include "./texture.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__rendertexture__fromRaylib(RenderTexture2D *renderTexture) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 3);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 3;
  result->fields = fields;

  fields[0] = {
    .name = "depth",
    .value = madraylib__texture__fromRaylib(&renderTexture->depth),
  };
  fields[1] = {
    .name = "id",
    .value = (void*)renderTexture->id,
  };
  fields[2] = {
    .name = "texture",
    .value = madraylib__texture__fromRaylib(&renderTexture->texture),
  };

  return result;
}

RenderTexture2D madraylib__rendertexture__toRaylib(madlib__record__Record_t * renderTexture) {
  return {
    .depth = madraylib__texture__toRaylib(((madlib__record__Record_t*) renderTexture->fields[0].value)),
    .id = (unsigned int) (int64_t) renderTexture->fields[1].value,
    .texture = madraylib__texture__toRaylib(((madlib__record__Record_t*) renderTexture->fields[2].value)),
  };
}


madlib__record__Record_t *madraylib__rendertexture__load(int32_t width, int32_t height) {
  RenderTexture2D renderTexture = LoadRenderTexture(width, height);
  return madraylib__rendertexture__fromRaylib(&renderTexture);
}

void madraylib__rendertexture__unload(madlib__record__Record_t *renderTexture) {
  UnloadRenderTexture(madraylib__rendertexture__toRaylib(renderTexture));
}

bool madraylib__rendertexture__isReady(madlib__record__Record_t *renderTexture) {
  return IsRenderTextureReady(madraylib__rendertexture__toRaylib(renderTexture));
}

void madraylib__rendertexture__beginTextureMode(madlib__record__Record_t *renderTexture) {
  BeginTextureMode(madraylib__rendertexture__toRaylib(renderTexture));
}

void madraylib__rendertexture__endTextureMode() {
  EndTextureMode();
}


#ifdef __cplusplus
}
#endif
