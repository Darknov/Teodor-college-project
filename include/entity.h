#ifndef _ENTITY_H
#define _ENTITY_H
#include <vector>
#include "console.h"
#include "world.h"
#include "bullet.h"

class World;

class Bullet;

class Entity
{
private:

protected:
    double x;
    double y;
    double previousX;
    double previousY;
    char lastKey;
    int hp;
    void onHit(Bullet* bullet);
    void checkIfBulletHit();
    char picture;
    Entity(int x, int y, char picture, World *world);
    World* world;
    void move(char direction);
public:

    double getX();
    double getY();
    int getHp();
    char getPicture();

    virtual void action() = 0;
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void HandleEvents() = 0;
};


#endif
