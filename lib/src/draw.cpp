#include <raylib.h>
#include <rlgl.h>

#include "color.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__draw__begin() { BeginDrawing(); }

void madraylib__draw__end() {
  EndDrawing();
}

void madraylib__draw__clearBackground(madlib__record__Record_t *c) {
  ClearBackground(madraylib__color__toRaylib(c));
}

void madraylib__draw__beginBlendMode(int32_t mode) { BeginBlendMode(mode); }

void madraylib__draw__endBlendMode(int32_t mode) { EndBlendMode(); }

#ifdef __cplusplus
}
#endif