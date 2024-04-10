#include "gc.h"
#include <raylib.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

void madraylib__window__init(int32_t w, int32_t h, char *title) {
  InitWindow(w, h, title);
}

void madraylib__window__setTargetFPS(int32_t fps) {
  SetTargetFPS(fps);
}

bool madraylib__window__shouldClose() {
  return WindowShouldClose();
}

void madraylib__window__close() {
  return CloseWindow();
}

#ifdef __cplusplus
}
#endif