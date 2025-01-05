#include "collision.h"
#include "bullet.h"
#include "raymath.h"
#include <stdio.h>

bool CheckCircleCollision(Vector2 centerA, float radiusA, Vector2 centerB,
                          float radiusB) {
  float dist = Vector2Distance(centerA, centerB);
  float combined = radiusA + radiusB;

  return (dist < combined);
}

void CheckCollisions(Player *player, Enemy enemies[], int MAX_ENEMIES,
                     Bullet bullets[], int MAX_BULLETS) {
  for (int b = 0; b < MAX_BULLETS; b++) {
    if (bullets[b].active) {
      if (bullets[b].team == TEAM_PLAYER)
        continue;

      if (CheckCircleCollision(player->position, player->radius,
                               bullets[b].position, bullets[b].radius)) {
        bullets[b].active = false;
        printf("Player hit\n");
      }
    }
  }

  for (int e = 0; e < MAX_ENEMIES; e++) {
    if (enemies[e].active) {
      for (int b = 0; b < MAX_BULLETS; b++) {
        if (bullets[b].active) {
          if (bullets[b].team == TEAM_ENEMY)
            continue;

          if (CheckCircleCollision(enemies[e].position, enemies[e].radius,
                                   bullets[b].position, bullets[b].radius)) {
            bullets[b].active = false;
            printf("Enemy hit\n");
          }
        }
      }
    }
  }
}
