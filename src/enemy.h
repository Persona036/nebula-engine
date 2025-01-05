#ifndef ENEMY_H
#define ENEMY_H

#include "bullet.h"
#include "raylib.h"

typedef struct Enemy {
  Vector2 position;
  float radius;
  float shootTimer;
  float currentAngle;
  bool active;
} Enemy;

void InitEnemy(Enemy *enemy, Vector2 startPos);
void UpdateEnemy(Enemy *enemy, Bullet bullets[], int maxBullets,
                 float deltatime);
void DrawEnemy(Enemy *enemy);

#endif
