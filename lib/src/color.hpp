#include "record.hpp"
#include <raylib.h>


#ifdef __cplusplus
extern "C" {
#endif

madlib__record__Record_t *madraylib__color__fromRaylib(Color *color);
Color *madraylib__color__toRaylib(madlib__record__Record_t *color);

#ifdef __cplusplus
}
#endif
