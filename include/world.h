#ifndef WORLD_H
#define WORLD_H
#include "map.h"
#include "bullet.h"
#include "entity.h"
#include <vector>
#include "game.h"

class Game;

class Entity;

class Bullet;

class World
{
public:
    Map* map;

    World(int difficulty,int x,int y);
    ~World();
    int getEntityNumber();
    int getX();
    int getY();
    bool isPlayerDead;
    int difficulty;
    std::vector<Bullet*> bullets;
    std::vector<Entity*> entities;
    void pushBullet(Bullet* bullet);
    void HandleEvents(Game *game);
    void Draw(Game *game);
    void Update(Game *game);
private:
    int x;
    int y;
    void generateEnemies(int amount);
    void handleEventsEntities();
    void handleEventsBullets();
    void updateEntities();
    void updateBullets();
    void drawEntities();
    void drawBullets();

    void pushEntity(Entity *entity);

};


#endif
