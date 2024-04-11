#include <raylib.h>

#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__rectangle__fromRaylib(Rectangle *rect);
Rectangle *madraylib__rectangle__toRaylib(madlib__record__Record_t *rectangle);

#ifdef __cplusplus
}
#endif
