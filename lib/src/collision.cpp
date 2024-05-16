#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

bool madraylib__collision__checkRecs(madlib__record__Record_t *rectangle1, madlib__record__Record_t *rectangle2) {
  return CheckCollisionRecs(madraylib__rectangle__toRaylib(rectangle1), madraylib__rectangle__toRaylib(rectangle2));
}

madlib__record__Record_t *madraylib__collision__getRec(madlib__record__Record_t *rectangle1, madlib__record__Record_t *rectangle2) {
  Rectangle collision = GetCollisionRec(madraylib__rectangle__toRaylib(rectangle1), madraylib__rectangle__toRaylib(rectangle2));
  return madraylib__rectangle__fromRaylib(&collision);
}

bool madraylib__collision__checkCircles(madlib__record__Record_t *center1, double radius1, madlib__record__Record_t *center2, double radius2) {
  return CheckCollisionCircles(madraylib__math__vector2ToRaylib(center1), radius1, madraylib__math__vector2ToRaylib(center2), radius2);
}

bool madraylib__collision__checkCircleRec(madlib__record__Record_t *center1, double radius1, madlib__record__Record_t *rectangle) {
  return CheckCollisionCircleRec(madraylib__math__vector2ToRaylib(center1), radius1, madraylib__rectangle__toRaylib(rectangle));
}

bool madraylib__collision__checkPointRec(madlib__record__Record_t *point, madlib__record__Record_t *rectangle) {
  return CheckCollisionPointRec(madraylib__math__vector2ToRaylib(point), madraylib__rectangle__toRaylib(rectangle));
}

bool madraylib__collision__checkPointCircle(madlib__record__Record_t *point, madlib__record__Record_t *center, double radius) {
  return CheckCollisionPointCircle(madraylib__math__vector2ToRaylib(point), madraylib__math__vector2ToRaylib(center), radius);
}

bool madraylib__collision__checkPointTriangle(madlib__record__Record_t *point, madlib__record__Record_t *p1, madlib__record__Record_t *p2, madlib__record__Record_t *p3) {
  return CheckCollisionPointTriangle(madraylib__math__vector2ToRaylib(point), madraylib__math__vector2ToRaylib(p1), madraylib__math__vector2ToRaylib(p2), madraylib__math__vector2ToRaylib(p3));
}

bool madraylib__collision__checkPointPoly(madlib__record__Record_t *point, madlib__array__Array_t *poly) {
  return CheckCollisionPointPoly(madraylib__math__vector2ToRaylib(point), madraylib__math__toPoints(poly), poly->length);
}

bool madraylib__collision__checkLines(madlib__record__Record_t *start1, madlib__record__Record_t *end1, madlib__record__Record_t *start2, madlib__record__Record_t *end2) {
  Vector2 collision;
  return CheckCollisionLines(madraylib__math__vector2ToRaylib(start1), madraylib__math__vector2ToRaylib(end1), madraylib__math__vector2ToRaylib(start2), madraylib__math__vector2ToRaylib(end2), &collision);
}

bool madraylib__collision__checkPointLine(madlib__record__Record_t *point, madlib__record__Record_t *start, madlib__record__Record_t *end, int32_t threshold) {
  return CheckCollisionPointLine(madraylib__math__vector2ToRaylib(point), madraylib__math__vector2ToRaylib(start), madraylib__math__vector2ToRaylib(end), threshold);
}

#ifdef __cplusplus
}
#endif