#include "bullet.h"
#include "collision.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

#define MAX_ENEMIES 1
#define MAX_BULLETS 1000
int main(void) {
  const int screenwidth = 800;
  const int screenheight = 600;

  setvbuf(stdout, NULL, _IONBF, 0);

  InitWindow(screenwidth, screenheight, "rescan");

  Player player;
  InitPlayer(&player, screenwidth / 2.0f, screenheight / 2.0f);

  Bullet bullets[MAX_BULLETS];
  InitBullet(bullets, MAX_BULLETS);

  Enemy enemies[MAX_ENEMIES];
  for (int i = 0; i < MAX_ENEMIES; i++) {
    Vector2 startPos = (Vector2){screenwidth / 2.0f, screenheight / 2.0f};
    InitEnemy(&enemies[i], startPos);
  }

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    if (IsKeyPressed(KEY_SPACE)) {
      SpawnBullet(bullets, MAX_BULLETS, player.position, (Vector2){0, -300},
                  TEAM_PLAYER);
    }

    UpdatePlayer(&player, deltaTime);
    for (int i = 0; i < MAX_ENEMIES; i++) {
      if (enemies[i].active) {
        UpdateEnemy(&enemies[i], bullets, MAX_BULLETS, deltaTime);
      }
    }
    UpdateBullets(bullets, MAX_BULLETS, deltaTime);

    CheckCollisions(&player, enemies, MAX_ENEMIES, bullets, MAX_BULLETS);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawPlayer(&player);
    for (int i = 0; i < MAX_ENEMIES; i++) {
      if (enemies[i].active) {
        DrawEnemy(&enemies[i]);
      }
    }
    DrawBullets(bullets, MAX_BULLETS);
    DrawText("nyomnyom", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
