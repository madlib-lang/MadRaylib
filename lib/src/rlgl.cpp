#include <raylib.h>
#include <rlgl.h>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void madraylib__gl__translatef(double x, double y, double z) {
  rlTranslatef(x, y, z);
}

void madraylib__gl__rotatef(double angle, double x, double y, double z) {
  rlRotatef(angle, x, y, z);
}

void madraylib__gl__scalef(double x, double y, double z) { rlScalef(x, y, z); }

#ifdef __cplusplus
}
#endif
