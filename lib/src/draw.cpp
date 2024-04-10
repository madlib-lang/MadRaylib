#include "gc.h"
#include <raylib.h>
#include "color.hpp"


#ifdef __cplusplus
extern "C" {
#endif

void madraylib__draw__begin() {
  BeginDrawing();
}

void madraylib__draw__end() {
  EndDrawing();
}

void madraylib__draw__clearBackground(madlib__record__Record_t *c) {
  ClearBackground(*madraylib__color__toRaylib(c));
}

#ifdef __cplusplus
}
#endif