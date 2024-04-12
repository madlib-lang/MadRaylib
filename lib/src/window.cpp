#include <raylib.h>
#include <stdint.h>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__window__init(int32_t w, int32_t h, char *title) {
  InitWindow(w, h, title);
}

void madraylib__window__setTargetFPS(int32_t fps) { SetTargetFPS(fps); }

bool madraylib__window__shouldClose() { return WindowShouldClose(); }

void madraylib__window__close() { return CloseWindow(); }

bool madraylib__window__isReady() { return IsWindowReady(); }

bool madraylib__window__isResized() { return IsWindowResized(); }

int32_t madraylib__window__getScreenWidth() { return GetScreenWidth(); }

int32_t madraylib__window__getScreenHeight() { return GetScreenHeight(); }

void madraylib__window__setConfigFlags(int32_t flags) { SetConfigFlags(flags); }

void madraylib__window__setWindowState(int32_t flags) { SetWindowState(flags); }

void madraylib__window__clearWindowState(int32_t flags) {
  ClearWindowState(flags);
}

bool madraylib__window__isWindowStateEnabled(int32_t flag) {
  IsWindowState(flag);
}

#ifdef __cplusplus
}
#endif