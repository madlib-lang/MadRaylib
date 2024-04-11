#include <raylib.h>
#include <rlgl.h>

#include "color.hpp"
#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__draw__begin() { BeginDrawing(); }

void madraylib__draw__end() { EndDrawing(); }

void madraylib__draw__clearBackground(madlib__record__Record_t *c) {
  ClearBackground(madraylib__color__toRaylib(c));
}

// void setDefaultShapeTexture() {
//   SetShapesTexture(GetFontDefault().texture, (Rectangle){ 0, 0, 1, 1 });
// }

#ifdef __cplusplus
}
#endif