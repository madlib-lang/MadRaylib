#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <raylib.h>
#include <rlgl.h>
#include <stdint.h>

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

void madraylib__gl__setBlendFactors(int32_t srcFactor, int32_t dstFactor,
                                    int32_t equation) {
  rlSetBlendFactors(srcFactor, dstFactor, equation);
}

void madraylib__gl__setBlendFactorsSeparate(
    int32_t srcFactorColor, int32_t dstFactorColor, int32_t equationColor,
    int32_t srcFactorAlpha, int32_t dstFactorAlpha, int32_t equationAlpha) {
  rlSetBlendFactorsSeparate(srcFactorColor, dstFactorColor, srcFactorAlpha,
                            dstFactorAlpha, equationColor, equationAlpha);
}

#ifdef __cplusplus
}
#endif
