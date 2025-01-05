#include "enemy.h"
#include "bullet.h"
#include "raylib.h"
#include "raymath.h"

void InitEnemy(Enemy *enemy, Vector2 startPos) {
  enemy->active = true;
  enemy->position = startPos;
  enemy->shootTimer = 1.0f;
  enemy->currentAngle = 0.0f;
  enemy->radius = 20.0f;
}

void UpdateEnemy(Enemy *enemy, Bullet *bullets, int maxBullets,
                 float deltatime) {
  if (!enemy->active)
    return;

  enemy->shootTimer -= deltatime;
  if (enemy->shootTimer <= 0.0f) {
    enemy->shootTimer = 0.02f;

    enemy->currentAngle += 10.0f;
    float radians = enemy->currentAngle * DEG2RAD;
    float speed = 200.0f;

    Vector2 velocity = {speed * cosf(radians), speed * sinf(radians)};

    SpawnBullet(bullets, maxBullets, enemy->position, velocity, TEAM_ENEMY);
    SpawnBullet(bullets, maxBullets, enemy->position,
                (Vector2){-velocity.x, -velocity.y}, TEAM_ENEMY);
    SpawnBullet(bullets, maxBullets, enemy->position,
                (Vector2){-velocity.x, velocity.y}, TEAM_ENEMY);
    SpawnBullet(bullets, maxBullets, enemy->position,
                (Vector2){velocity.x, -velocity.y}, TEAM_ENEMY);
  }
}

void DrawEnemy(Enemy *enemy) {
  if (!enemy->active)
    return;
  DrawCircleV(enemy->position, 20, DARKBLUE);
}
