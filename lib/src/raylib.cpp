#include <raylib.h>
#include <stdio.h>

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

void runRaylib() {
  auto texture = (Texture2D *)GC_MALLOC(sizeof(Texture2D));
  auto _texture = LoadTexture("./sprite.png");
  *texture = _texture;

  int x = 0;
  // Update
  //----------------------------------------------------------------------------------
  // TODO: Update your variables here
  //----------------------------------------------------------------------------------
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  Rectangle *rect = (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  rect->x = 200;
  rect->y = 200;
  rect->width = 200;
  rect->height = 200;

  x++;

  Rectangle *textureRect = (Rectangle *)GC_MALLOC(sizeof(Rectangle));
  textureRect->x = x;
  textureRect->y = 200;
  textureRect->width = 100;
  textureRect->height = 100;

  // Draw
  //----------------------------------------------------------------------------------
  BeginDrawing();
  ClearBackground(RAYWHITE);
  Rectangle playerRect = {20, 40, 40, 40};
  DrawRectangleRec(*rect, RED);
  DrawTextureRec(*texture, *textureRect, {10, 10}, {255, 255, 255, 255});
  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

  EndDrawing();

  UnloadTexture(*texture);
}

#ifdef __cplusplus
}
#endif