#include "bullet.h"
#include "stdio.h"

void InitBullet(Bullet *bullets, int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    bullets[i].active = false;
    bullets[i].radius = 4.0f;
    bullets[i].team = TEAM_ENEMY;
  }
}

void SpawnBullet(Bullet *bullets, int maxCount, Vector2 spawnPos,
                 Vector2 velocity, BulletTeam team) {
  for (int i = 0; i < maxCount; i++) {
    if (!bullets[i].active) {
      bullets[i].active = true;
      bullets[i].position = spawnPos;
      bullets[i].velocity = velocity;
      bullets[i].team = team;
      return;
    }
  }
}

void UpdateBullets(Bullet *bullets, int maxCount, float deltaTime) {
  for (int i = 0; i < maxCount; i++) {
    if (bullets[i].active) {
      bullets[i].position.x += bullets[i].velocity.x * deltaTime;
      bullets[i].position.y += bullets[i].velocity.y * deltaTime;

      int screenW = GetScreenWidth();
      int screenH = GetScreenHeight();

      if (bullets[i].position.x < -10 || bullets[i].position.x > screenW + 10 ||
          bullets[i].position.y < -10 || bullets[i].position.y > screenH + 10) {
        bullets[i].active = false;
      }
    }
  }
}

void DrawBullets(Bullet *bullets, int maxCount) {
  for (int i = 0; i < maxCount; i++) {
    DrawCircleV(bullets[i].position, bullets[i].radius, RED);
  }
}
