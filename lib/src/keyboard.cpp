#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

bool madraylib__keyboard__isKeyPressed(int32_t key) {
  return IsKeyPressed(key);
}

bool madraylib__keyboard__isKeyPressedRepeat(int32_t key) {
  return IsKeyPressedRepeat(key);
}

bool madraylib__keyboard__isKeyDown(int32_t key) { return IsKeyDown(key); }

bool madraylib__keyboard__isKeyReleased(int32_t key) {
  return IsKeyReleased(key);
}
bool madraylib__keyboard__isKeyUp(int32_t key) { return IsKeyUp(key); }

#ifdef __cplusplus
}
#endif