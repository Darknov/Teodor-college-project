#ifndef _ENEMY_H
#define _ENEMY_H
#include <entity.h>

class Enemy : public Entity
{
private:

public:
    Enemy(int x, int y, char picture, World *world);
    void action();
    void Draw();
    void Update();
    void HandleEvents();
    void tryFire();
};

#endif
