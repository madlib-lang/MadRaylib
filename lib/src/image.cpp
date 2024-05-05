#include <raylib.h>
#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./rectangle.hpp"
#include "array.hpp"
#include "bytearray.hpp"
#include "gc.h"
#include "number.hpp"
#include "record.hpp"

#ifdef __cplusplus
extern "C" {
#endif

Image madraylib__image__toRaylib(madlib__record__Record_t *image) {
  return {
      .data = (void *)((madlib__bytearray__ByteArray_t *)image->fields[0].value)
                  ->bytes,
      .format = (int32_t)(uint64_t)image->fields[1].value,
      .height = (int32_t)(uint64_t)image->fields[2].value,
      .mipmaps = (int32_t)(uint64_t)image->fields[3].value,
      .width = (int32_t)(int64_t)image->fields[4].value,
  };
}

madlib__record__Record_t *madraylib__image__fromRaylib(Image *image) {
  madlib__record__Field_t *fields =
      (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 5);
  madlib__record__Record_t *result =
      (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 5;
  result->fields = fields;

  madlib__bytearray__ByteArray_t *data =
      (madlib__bytearray__ByteArray_t *)GC_MALLOC(
          sizeof(madlib__bytearray__ByteArray_t));
  data->capacity = image->width * image->height;
  data->length = image->width * image->height;
  data->bytes = (unsigned char *)image->data;

  fields[0] = {
      .name = "data",
      .value = (void *)data,
  };
  fields[1] = {
      .name = "format",
      .value = (void *)image->format,
  };
  fields[2] = {
      .name = "height",
      .value = (void *)image->height,
  };
  fields[3] = {
      .name = "mipmaps",
      .value = (void *)image->mipmaps,
  };
  fields[4] = {
      .name = "width",
      .value = (void *)image->width,
  };

  return result;
}

madlib__record__Record_t *madraylib__image__load(char *filename) {
  Image image = LoadImage(filename);
  return madraylib__image__fromRaylib(&image);
}

madlib__record__Record_t *madraylib__image__format(
    int32_t format, madlib__record__Record_t *image) {
  Image raylibImage = madraylib__image__toRaylib(image);
  ImageFormat(&raylibImage, format);
  image->fields[1].value = (void *)format;
  ((madlib__bytearray__ByteArray_t *)image->fields[0].value)->bytes =
      (unsigned char *)raylibImage.data;
  return madraylib__image__fromRaylib(&raylibImage);
}

#ifdef __cplusplus
}
#endif
