#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
  Vector2 position;
  float radius;
  float speed;
} Player;

void InitPlayer(Player *player, float x, float y);
void UpdatePlayer(Player *player, float deltaTime);
void DrawPlayer(const Player *player);

#endif
