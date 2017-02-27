#include "enemy.h"
#include "bullet.h"
#include <ctime>
#include <string>


Enemy::Enemy(int x, int y, char picture, World *world): Entity(x,y,picture,world)
{
    this->hp = 10;

}

void Enemy::tryFire()
{
    if(this->world->entities[0]->getX() == this->x)
    {
        if(this->world->entities[0]->getY() < this->y)
        {
            this->world->pushBullet(new Bullet(this->getX(),this->getY()-1,this->world->difficulty,'o','w',this->world));
        }
        else
        {
            this->world->pushBullet(new Bullet(this->getX(),this->getY()+1,this->world->difficulty,'o','s',this->world));
        }
    }
    else if(this->world->entities[0]->getY() == this->y)
    {
        if(this->world->entities[0]->getX() < this->x)
        {
            this->world->pushBullet(new Bullet(this->getX()-1,this->getY(),this->world->difficulty,'o','a',this->world));
        }
        else
        {
            this->world->pushBullet(new Bullet(this->getX()+1,this->getY(),this->world->difficulty,'o','d',this->world));
        }
    }



}

void Enemy::action()
{
    int random = rand()%10;
    if(random==0 && (this->getY() > 1))
    {
        this->move('w');
    }
    else if(random==1 && (this->getY() < (this->world->getY() - 2)))
    {
        this->move('s');
    }
    else if(random==2 && (this->getX() > 1))
    {
        this->move('a');
    }
    else if(random==3 && (this->getX() < (this->world->getX() - 2)))
    {
        this->move('d');
    }
    this->tryFire();
}

void Enemy::Draw()
{
    Console::Draw(' ',this->previousX,this->previousY);
    if(this->hp > 0)
        Console::Draw(this->getPicture(),this->getX(),this->getY());
    else
        Console::Draw(' ',this->getX(),this->getY());
}

void Enemy::Update()
{
    this->action();
    this->checkIfBulletHit();
    if(this->hp <= 0)
        this->Draw();
}

void Enemy::HandleEvents()
{

}
