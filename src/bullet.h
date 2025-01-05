#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

typedef enum { TEAM_PLAYER, TEAM_ENEMY } BulletTeam;

typedef struct Bullet {
  Vector2 position;
  Vector2 velocity;
  float radius;
  bool active;
  BulletTeam team;
} Bullet;

void InitBullet(Bullet bullets[], int maxCount);
void SpawnBullet(Bullet bullets[], int maxCount, Vector2 spawnPos,
                 Vector2 velocity, BulletTeam team);
void UpdateBullets(Bullet bullets[], int maxCount, float deltaTime);
void DrawBullets(Bullet bullets[], int maxCount);

#endif
