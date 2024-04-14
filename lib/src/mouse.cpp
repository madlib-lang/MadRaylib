#include <raylib.h>
#include <stdint.h>

#include "./math.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// RLAPI float GetMouseWheelMove(void); // Get mouse wheel
// movement for X or Y, whichever is larger RLAPI Vector2
// GetMouseWheelMoveV(void);                       // Get mouse wheel movement
// for both X and Y RLAPI void SetMouseCursor(int cursor); // Set mouse cursor

bool madraylib__mouse__isButtonPressed(int32_t button) {
  return IsMouseButtonPressed(button);
}

bool madraylib__mouse__isMouseButtonDown(int32_t button) {
  return IsMouseButtonDown(button);
}

bool madraylib__mouse__isMouseButtonReleased(int32_t button) {
  return IsMouseButtonReleased(button);
}

bool madraylib__mouse__isMouseButtonUp(int32_t button) {
  return IsMouseButtonUp(button);
}

int32_t madraylib__mouse__getX() { return GetMouseX(); }

int32_t madraylib__mouse__getY() { return GetMouseY(); }

madlib__record__Record_t *madraylib__mouse__getMousePosition() {
  auto position = GetMousePosition();
  return madraylib__math__vector2FromRaylib(&position);
}

madlib__record__Record_t *madraylib__mouse__getMouseDelta() {
  auto delta = GetMouseDelta();
  return madraylib__math__vector2FromRaylib(&delta);
}

void madraylib__mouse__setMousePosition(int32_t x, int32_t y) {
  SetMousePosition(x, y);
}

void madraylib__mouse__setMouseOffset(int32_t x, int32_t y) {
  SetMouseOffset(x, y);
}

void madraylib__mouse__setMouseScale(double x, double y) {
  SetMouseScale(x, y);
}

float madraylib__mouse__getMouseWheelMove() { GetMouseWheelMove(); }

madlib__record__Record_t *madraylib__mouse__getMouseWheelMoveV() {
  auto wheelMove = GetMouseWheelMoveV();
  madraylib__math__vector2FromRaylib(&wheelMove);
}

void madraylib__mouse__setMouseCursor(int32_t cursor) {
  SetMouseCursor(cursor);
}

#ifdef __cplusplus
}
#endif
