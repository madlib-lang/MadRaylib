#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "array.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Texture2D madraylib__texture__toRaylib(madlib__record__Record_t *texture) {
  return {
      .format = (int32_t)(uint64_t)texture->fields[0].value,
      .height = (int32_t)(uint64_t)texture->fields[1].value,
      .id = (uint32_t)(int64_t)texture->fields[2].value,
      .mipmaps = (int32_t)(uint64_t)texture->fields[3].value,
      .width = (int32_t)(int64_t)texture->fields[4].value,
  };
}

madlib__record__Record_t *madraylib__texture__fromRaylib(Texture2D *texture) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 5);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 5;
  result->fields = fields;

  fields[0] = {
    .name = "format",
    .value = (void *)texture->format,
  };
  fields[1] = {
    .name = "height",
    .value = (void *)texture->height,
  };
  fields[2] = {
    .name = "id",
    .value = (void *)texture->id,
  };
  fields[3] = {
    .name = "mipmaps",
    .value = (void *)texture->mipmaps,
  };
  fields[4] = {
    .name = "width",
    .value = (void *)texture->width,
  };

  return result;
}

madlib__record__Record_t *madraylib__texture__load(char *c) {
  Texture2D texture = LoadTexture(c);
  return madraylib__texture__fromRaylib(&texture);
}

madlib__record__Record_t *madraylib__texture__unload(madlib__record__Record_t *texture) {
  UnloadTexture(madraylib__texture__toRaylib(texture));
}

void madraylib__texture__draw(madlib__record__Record_t *texture, double x, double y, madlib__record__Record_t *color) {
  DrawTexture(madraylib__texture__toRaylib(texture), x, y, madraylib__color__toRaylib(color));
}

void madraylib__texture__drawV(madlib__record__Record_t *texture, madlib__record__Record_t *position, madlib__record__Record_t *color) {
  DrawTextureV(madraylib__texture__toRaylib(texture), madraylib__math__vector2ToRaylib(position), madraylib__color__toRaylib(color));
}

void madraylib__texture__drawEx(madlib__record__Record_t *texture, madlib__record__Record_t *position, double rotation, double scale, madlib__record__Record_t *color) {
  DrawTextureEx(madraylib__texture__toRaylib(texture), madraylib__math__vector2ToRaylib(position), rotation, scale, madraylib__color__toRaylib(color));
}

void madraylib__texture__drawRec(madlib__record__Record_t *texture, madlib__record__Record_t *rectangle,
                                 madlib__record__Record_t *position, madlib__record__Record_t *color) {
  DrawTextureRec(madraylib__texture__toRaylib(texture), madraylib__rectangle__toRaylib(rectangle),
                 madraylib__math__vector2ToRaylib(position), madraylib__color__toRaylib(color));
}

void madraylib__texture__drawPro(madlib__record__Record_t *texture, madlib__record__Record_t *source, madlib__record__Record_t *dest, madlib__record__Record_t* origin, double rotation, madlib__record__Record_t *color) {
  DrawTexturePro(
    madraylib__texture__toRaylib(texture),
    madraylib__rectangle__toRaylib(source),
    madraylib__rectangle__toRaylib(dest),
    madraylib__math__vector2ToRaylib(origin),
    rotation,
    madraylib__color__toRaylib(color)
  );
}

#ifdef __cplusplus
}
#endif
