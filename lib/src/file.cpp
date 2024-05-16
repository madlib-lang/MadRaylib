#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include "bytearray.hpp"
#include <raylib.h>

#ifdef __cplusplus
extern "C" {
#endif

char *madraylib__file__loadText(char *path) {
  return LoadFileText(path);
}

#ifdef __cplusplus
}
#endif
