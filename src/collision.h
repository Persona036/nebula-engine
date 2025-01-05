#ifndef COLLISION_H
#define COLLISION_H
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"

bool CheckCircleCollision(Vector2 centerA, float radiusA, Vector2 centerB,
                          float radiusB);
void CheckCollisions(Player *player, Enemy enemies[], int MAX_ENEMIES,
                     Bullet bullets[], int MAX_BULLETS);
#endif
