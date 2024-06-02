#ifndef GC_THREADS
  #define GC_THREADS
#endif

#include <stdint.h>

#include "./color.hpp"
#include "./math.hpp"
#include "./texture.hpp"
#include "./rectangle.hpp"
#include "gc.h"
#include "number.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MATERIAL_MAPS 12

MaterialMap madraylib__material__materialMapToRaylib(madlib__record__Record_t *materialMap) {
  return {
    .color = madraylib__color__toRaylib((madlib__record__Record_t*) materialMap->fields[0].value),
    .texture = madraylib__texture__toRaylib((madlib__record__Record_t*) materialMap->fields[1].value),
    .value = (float) unboxDouble(materialMap->fields[2].value),
  };
}

Material madraylib__material__materialToRaylib(madlib__record__Record_t *material) {
//       fields[0] = {
//     .name = "maps",
//     .value = maps,
//   };

//   fields[1] = {
//     .name = "params",
//     .value = material->params,
//   };

//   Shader *shader = (Shader *)GC_MALLOC(sizeof(Shader));
//   *shader = material->shader;
//   fields[2] = {
//     .name = "shader",
//     .value = shader,
//   };

  madlib__array__Array_t *madlibMaterialMaps = (madlib__array__Array_t *) material->fields[0].value;
  MaterialMap *maps = (MaterialMap *) GC_MALLOC(sizeof(MaterialMap) * MAX_MATERIAL_MAPS);

  for (int i = 0; i < MAX_MATERIAL_MAPS; i++) {
    maps[i] = madraylib__material__materialMapToRaylib((madlib__record__Record_t *) madlibMaterialMaps->items[i]);
  }

  return {
    .maps = maps,
    .params = { 0.0, 0.0, 0.0, 0.0 }, //TODO: fix
    .shader = *((Shader *) material->fields[2].value),
  };
}

Mesh madraylib__mesh__toRaylib(madlib__record__Record_t *mesh) {
  int vertexCount = (int64_t)mesh->fields[13].value;
  int triangleCount = (int64_t)mesh->fields[10].value;

  void **madlibNormals = (void**)mesh->fields[6].value;
  float *normals = (float *) GC_MALLOC(sizeof(float) * vertexCount * 3);
  for (int i = 0; i < vertexCount * 3; i++) {
    normals[i] = unboxDouble(madlibNormals[i]);
  }

  void **madlibTexcoords = (void**)mesh->fields[8].value;
  float *texcoords = (float *) GC_MALLOC(sizeof(float) * vertexCount * 2);
  for (int i = 0; i < vertexCount * 2; i++) {
    texcoords[i] = unboxDouble(madlibTexcoords[i]);
  }

  void **madlibVertices = (void**)mesh->fields[14].value;
  float *vertices = (float *) GC_MALLOC(sizeof(float) * vertexCount * 3);
  for (int i = 0; i < vertexCount * 3; i++) {
    vertices[i] = unboxDouble(madlibVertices[i]);
  }

  return {
    .animNormals = NULL,
    .animVertices = NULL,
    .boneIds = NULL,
    .boneWeights = NULL,
    .colors = NULL,
    .indices = NULL,
    .normals = normals,
    .tangents = NULL,
    .texcoords = texcoords,
    .texcoords2 = NULL,
    .triangleCount = triangleCount,
    .vaoId = (unsigned int) (int64_t) mesh->fields[11].value,
    .vboId = (unsigned int*) mesh->fields[12].value,
    .vertexCount = vertexCount,
    .vertices = vertices,
  };
}


Model madraylib__model__toRaylib(madlib__record__Record_t *model) {
  int meshCount = (int64_t) model->fields[5].value;
  int materialCount = (int64_t) model->fields[3].value;
  madlib__array__Array_t *madlibMeshes = (madlib__array__Array_t*)model->fields[7].value;
  Mesh *meshes = (Mesh *) GC_MALLOC(sizeof(Mesh) * meshCount);
  for (int i = 0; i < meshCount; i++) {
    meshes[i] = madraylib__mesh__toRaylib((madlib__record__Record_t *) madlibMeshes->items[i]);
  }

  madlib__array__Array_t *madlibMaterials = (madlib__array__Array_t*)model->fields[4].value;
  Material *materials = (Material *) GC_MALLOC(sizeof(Material) * materialCount);
  for (int i = 0; i < materialCount; i++) {
    materials[i] = madraylib__material__materialToRaylib((madlib__record__Record_t *) madlibMaterials->items[i]);
  }


    // Model model = { 0 };

    // model.transform = MatrixIdentity();

    // model.meshCount = 1;
    // model.meshes = (Mesh *)RL_CALLOC(model.meshCount, sizeof(Mesh));
    // model.meshes[0] = mesh;

    // model.materialCount = 1;
    // model.materials = (Material *)RL_CALLOC(model.materialCount, sizeof(Material));
    // model.materials[0] = LoadMaterialDefault();

    // model.meshMaterial = (int *)RL_CALLOC(model.meshCount, sizeof(int));
    // model.meshMaterial[0] = 0;  // First material index

    // return model;

  return {
    .bindPose = NULL,
    .boneCount = NULL,
    .bones = NULL,
    .materialCount = materialCount,
    .materials = materials,
    .meshCount = meshCount,
    .meshMaterial = (int*) model->fields[6].value,
    .meshes = meshes,
    .transform = *((Matrix*) model->fields[8].value),
  };
}


madlib__record__Record_t *madraylib__material__materialMapFromRaylib(MaterialMap *materialMap) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 3);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 3;
  result->fields = fields;

  fields[0] = {
    .name = "color",
    .value = madraylib__color__fromRaylib(&materialMap->color),
  };

  fields[1] = {
    .name = "texture",
    .value = madraylib__texture__fromRaylib(&materialMap->texture),
  };

  fields[2] = {
    .name = "value",
    .value = boxDouble(materialMap->value),
  };

  return result;
}

madlib__record__Record_t *madraylib__material__materialFromRaylib(Material *material) {

  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 3);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 3;
  result->fields = fields;

//   MAX_MATERIAL_MAPS
  madlib__array__Array_t *maps = (madlib__array__Array_t *) GC_MALLOC(sizeof(madlib__array__Array_t));
  maps->length = MAX_MATERIAL_MAPS;
  maps->capacity = MAX_MATERIAL_MAPS;
  maps->items = (void**) GC_MALLOC(sizeof(void*) * MAX_MATERIAL_MAPS);
  for (int i = 0; i < MAX_MATERIAL_MAPS; i++) {
    maps->items[i] = madraylib__material__materialMapFromRaylib(&material->maps[i]);
  }
  fields[0] = {
    .name = "maps",
    .value = maps,
  };

  fields[1] = {
    .name = "params",
    .value = material->params,
  };

  Shader *shader = (Shader *)GC_MALLOC(sizeof(Shader));
  *shader = material->shader;
  fields[2] = {
    .name = "shader",
    .value = shader,
  };

  return result;
}


madlib__record__Record_t *madraylib__mesh__fromRaylib(Mesh *mesh) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 15);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 15;
  result->fields = fields;

  fields[0] = {
    .name = "animNormals",
    .value = NULL,
  };

  fields[1] = {
    .name = "animVertices",
    .value = NULL,
  };

  fields[2] = {
    .name = "boneIds",
    .value = NULL,
  };

  fields[3] = {
    .name = "boneWeights",
    .value = NULL,
  };

  fields[4] = {
    .name = "colors",
    .value = NULL,
  };

  fields[5] = {
    .name = "indices",
    .value = NULL,
  };

  madlib__array__Array_t *normals = (madlib__array__Array_t*) GC_MALLOC(sizeof(madlib__array__Array_t));
  normals->length = mesh->vertexCount * 3;
  normals->capacity = mesh->vertexCount * 3;
  normals->items = (void**) GC_MALLOC(sizeof(void*) * normals->length);
  for (int i = 0; i < normals->length; i++) {
    normals->items[i] = boxDouble(mesh->normals[i]);
  }
  fields[6] = {
    .name = "normals",
    .value = normals,
  };

  fields[7] = {
    .name = "tangents",
    .value = NULL,
  };

  madlib__array__Array_t *texcoords = (madlib__array__Array_t*) GC_MALLOC(sizeof(madlib__array__Array_t));
  texcoords->length = mesh->vertexCount * 2;
  texcoords->capacity = mesh->vertexCount * 2;
  texcoords->items = (void**) GC_MALLOC(sizeof(void*) * texcoords->length);
  for (int i = 0; i < texcoords->length; i++) {
    texcoords->items[i] = boxDouble(mesh->texcoords[i]);
  }
  fields[8] = {
    .name = "texcoords",
    .value = texcoords,
  };

  fields[9] = {
    .name = "texcoords2",
    .value = NULL,
  };

  fields[10] = {
    .name = "triangleCount",
    .value = (void *) mesh->triangleCount,
  };

  fields[11] = {
    .name = "vaoId",
    .value = (void *) mesh->vaoId,
  };

  fields[12] = {
    .name = "vboId",
    .value = (void *) mesh->vboId,
  };

  fields[13] = {
    .name = "vertexCount",
    .value = (void *) mesh->vertexCount,
  };

  madlib__array__Array_t *vertices = (madlib__array__Array_t*) GC_MALLOC(sizeof(madlib__array__Array_t));
  vertices->length = mesh->vertexCount * 3;
  vertices->capacity = mesh->vertexCount * 3;
  vertices->items = (void**) GC_MALLOC(sizeof(void*) * vertices->length);
  for (int i = 0; i < vertices->length; i++) {
    vertices->items[i] = boxDouble(mesh->vertices[i]);
  }
  fields[14] = {
    .name = "vertices",
    .value = vertices,
  };

  return result;
}


madlib__record__Record_t *madraylib__model__fromRaylib(Model *model) {
  madlib__record__Field_t *fields = (madlib__record__Field_t *)GC_MALLOC(sizeof(madlib__record__Field_t) * 9);
  madlib__record__Record_t *result = (madlib__record__Record_t *)GC_MALLOC(sizeof(madlib__record__Record_t));
  result->fieldCount = 9;
  result->fields = fields;

  fields[0] = {
    .name = "bindPose",
    .value = NULL,
  };

  fields[1] = {
    .name = "boneCount",
    .value = (void*) model->boneCount,
  };

  fields[2] = {
    .name = "bones",
    .value = NULL,
  };

  fields[3] = {
    .name = "materialCount",
    .value = (void*) model->materialCount,
  };

  madlib__array__Array_t *materials = (madlib__array__Array_t*) GC_MALLOC(sizeof(madlib__array__Array_t));
  materials->capacity = model->materialCount;
  materials->length = model->materialCount;
  materials->items = (void**) GC_MALLOC(sizeof(void*) * materials->length);

  for (int i = 0; i < materials->length; i++) {
    materials->items[i] = madraylib__material__materialFromRaylib(&model->materials[i]);
  }

  fields[4] = {
    .name = "materials",
    .value = materials,
  };

  fields[5] = {
    .name = "meshCount",
    .value = (void*) model->meshCount,
  };

  fields[6] = {
    .name = "meshMaterial",
    .value = model->meshMaterial,
  };

  madlib__array__Array_t *meshes = (madlib__array__Array_t*) GC_MALLOC(sizeof(madlib__array__Array_t));
  meshes->length = model->meshCount;
  meshes->capacity = model->meshCount;
  meshes->items = (void**) GC_MALLOC(sizeof(void*) * meshes->length);
  for (int i = 0; i < meshes->length; i++) {
    meshes->items[i] = madraylib__mesh__fromRaylib(&model->meshes[i]);
  }
  fields[7] = {
    .name = "meshes",
    .value = meshes,
  };

  Matrix *transform = (Matrix*) GC_MALLOC(sizeof(Matrix));
  *transform = model->transform;
  fields[8] = {
    .name = "transform",
    .value = transform,
  };

  return result;
}

void *madraylib__model__load(char *filename) {
  Model m = LoadModel(filename);
  return madraylib__model__fromRaylib(&m);
}

// RLAPI void DrawModel(Model model, Vector3 position, float scale, Color tint); 

void madraylib__model__draw(madlib__record__Record_t *model, madlib__record__Record_t *position, double scale, madlib__record__Record_t *color) {
  DrawModel(madraylib__model__toRaylib(model), madraylib__math__vector3ToRaylib(position), scale, madraylib__color__toRaylib(color));
}

// void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);

void madraylib__model__drawEx(madlib__record__Record_t *model, madlib__record__Record_t *position, madlib__record__Record_t *rotationAxis, double rotationAngle, madlib__record__Record_t *scale, madlib__record__Record_t *color) {
  DrawModelEx(madraylib__model__toRaylib(model), madraylib__math__vector3ToRaylib(position), madraylib__math__vector3ToRaylib(rotationAxis), rotationAngle, madraylib__math__vector3ToRaylib(scale), madraylib__color__toRaylib(color));
}

#ifdef __cplusplus
}
#endif
