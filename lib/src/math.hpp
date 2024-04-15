#include <raylib.h>

#include "record.hpp"
#include "array.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Vector2 madraylib__math__vector2ToRaylib(madlib__record__Record_t *vec2);
Vector3 madraylib__math__vector3ToRaylib(madlib__record__Record_t *vec3);
Vector4 madraylib__math__vector4ToRaylib(madlib__record__Record_t *vec4);
madlib__record__Record_t *madraylib__math__vector2FromRaylib(Vector2 *vec2);
madlib__record__Record_t *madraylib__math__vector3FromRaylib(Vector3 *vec3);
madlib__record__Record_t *madraylib__math__vector4FromRaylib(Vector4 *vec4);

Vector2 *madraylib__math__toPoints(madlib__array__Array_t *madlibPoints);
Vector3 *madraylib__math__to3DPoints(madlib__array__Array_t *madlibPoints);

#ifdef __cplusplus
}
#endif
