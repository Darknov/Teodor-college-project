#include <bullet.h>
#include "console.h"
#include <string>

Bullet::Bullet(double x, double y, double power, char picture, char direction, World *world)
    :x(x),y(y),power(power),picture(picture),direction(direction), world(world)
{
    this->isHit = false;
    this->isInBoundary();
}

double Bullet::getX()
{
    return this->x;
}

double Bullet::getY()
{
    return this->y;
}

double Bullet::getPower()
{
    return this->power;
}

void Bullet::move()
{
    switch(this->direction)
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

void Bullet::onHit()
{
    this->isHit = true;
}

bool Bullet::isInBoundary()
{
    if(this->x < 1 || this->x > this->world->getX() - 2 || this->y < 1 || this->y > this->world->getY() - 2 || this->isHit)
    {
        return false;
    }
    return true;
}



char Bullet::getPicture()
{
    return this->picture;
}

void Bullet::removePreviousPicture()
{
    switch(this->direction)
    {
    case 's':
        Console::Draw(' ',this->getX(),this->getY()-1);
        break;
    case 'a':
        Console::Draw(' ',this->getX()+1,this->getY());
        break;
    case 'w':
        Console::Draw(' ',this->getX(),this->getY()+1);
        break;
    case 'd':
        Console::Draw(' ',this->getX()-1,this->getY());
        break;
    default:;
    }
}

void Bullet::HandleEvents()
{

}

void Bullet::Draw()
{
    if(!isHit)
        this->removePreviousPicture();
    if(!isHit && isInBoundary())
        Console::Draw(this->getPicture(),this->getX(),this->getY());

}

void Bullet::Update()
{
    this->isHit = !this->isInBoundary();
    this->move();
    if(isHit)
        this->Draw();
}

