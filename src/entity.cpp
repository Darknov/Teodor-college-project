#include "entity.h"

Entity::Entity(int x, int y, char picture, World *world)
    :x(x),y(y),picture(picture),world(world)
{

}


void Entity::move(char direction)
{
    this->previousY = y;
    this->previousX = x;
    this->lastKey = direction;
    switch(direction)
    {
    case 's':
        this->y += 1;
        break;
    case 'a':
        this->x -= 1;
        break;
    case 'w':
        this->y -= 1;
        break;
    case 'd':
        this->x += 1;
        break;
    default:;
    }
}

double Entity::getX()
{
    return this->x;
}

double Entity::getY()
{
    return this->y;
}

int Entity::getHp()
{
    return this->hp;
}

void Entity::onHit(Bullet* bullet)
{
    this->hp -= bullet->getPower();
}

void Entity::checkIfBulletHit()
{
    for(auto& it : this->world->bullets){
        if(it->getX() == this->x && it->getY() == this->y)
        {
            this->onHit(it);
            it->onHit();
        }
    }
}

char Entity::getPicture()
{
    return this->picture;
}

