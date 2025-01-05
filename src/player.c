#include "player.h"
#include "raylib.h"

void InitPlayer(Player *player, float x, float y) {
  player->position = (Vector2){x, y};
  player->radius = 8.0f;
  player->speed = 200.0f;
}

void UpdatePlayer(Player *player, float deltaTime) {
  if (IsKeyDown(KEY_W)) {
    player->position.y -= player->speed * deltaTime;
  }
  if (IsKeyDown(KEY_S)) {
    player->position.y += player->speed * deltaTime;
  }
  if (IsKeyDown(KEY_A)) {
    player->position.x -= player->speed * deltaTime;
  }
  if (IsKeyDown(KEY_D)) {
    player->position.x += player->speed * deltaTime;
  }
}
void DrawPlayer(const Player *player) {
  DrawCircleV(player->position, player->radius, BLUE);
}
