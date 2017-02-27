#ifndef _BULLET_H
#define _BULLET_H
#include <string>
#include <vector>
#include "world.h"
#include "entity.h"

class World;

class Entity;

class Bullet
{
private:

    double x;
    double y;
    double power;
    char picture;
    char direction;
    World *world;
    std::vector<Bullet*> bullets;

public:
    Bullet(double x, double y, double power, char picture, char direction, World* world);
    double getX();
    double getY();
    bool isHit;
    double getPower();
    bool isInBoundary();
    char getPicture();
    void removePreviousPicture();
    void move();
    void onHit();
    void Draw();
    void Update();
    void HandleEvents();

};


#endif
