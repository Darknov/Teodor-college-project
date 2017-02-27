#include "world.h"
#include "console.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <algorithm>

World::World(int difficulty,int x,int y)
    : difficulty(difficulty),x(x),y(y)
{
    this->map = new Map(this->x,this->y);
    Entity *player = new Player(5,5,'P',this);
    pushEntity(player);
    this->isPlayerDead = false;
    this->map->Draw();
    Entity *enemy = new Enemy(23,8,'E',this);
    pushEntity(enemy);
}

World::~World()
{
    auto i = std::begin(this->entities);

    while (i != std::end(this->entities)) {
        delete *i;
        i = this->entities.erase(i);
    }

}

int World::getX()
{
    return this->x;
}

int World::getY()
{
    return this->y;
}

int World::getEntityNumber()
{
    return this->entities.size();
}

void World::generateEnemies(int amount)
{
    if(this->getEntityNumber() == 1)
    {
        for(int i=0; i < amount; i++)
        {
            this->pushEntity(new Enemy(rand()%(this->getX()-2)+1, rand()%(this->getY()-2)+1, 'E', this ));
        }
    }
}

void World::pushEntity(Entity* entity)
{
    this->entities.push_back(entity);
}

void World::pushBullet(Bullet* bullet)
{
    this->bullets.push_back(bullet);
}

void World::handleEventsEntities()
{
    for(auto& it : this->entities){
        it->HandleEvents();
    }
}

void World::handleEventsBullets()
{
    for(auto& it : this->bullets){
        it->HandleEvents();
    }
}

void World::updateEntities()
{
    auto i = std::begin(this->entities);

    while (i != std::end(this->entities)) {
        (*i)->Update();
        if(entities[0]->getHp() <= 0)
        {
            this->isPlayerDead = true;
        }
        if ((*i)->getHp() <= 0)
        {

            delete *i;
            i = this->entities.erase(i);
        }
        else
            ++i;
    }
}

void World::updateBullets()
{
    auto i = std::begin(this->bullets);

    while (i != std::end(this->bullets)) {
        (*i)->Update();
        if ((*i)->isHit)
        {
            delete *i;
            i = this->bullets.erase(i);
        }
        else
            ++i;
    }
}

void World::drawEntities()
{
    for(auto& it : this->entities){
        it->Draw();
    }
}

void World::drawBullets()
{
    for(auto& it : this->bullets){
        it->Draw();
    }
}

void World::HandleEvents(Game *game)
{
    this->handleEventsEntities();
    this->handleEventsBullets();
}

void World::Update(Game *game)
{
    this->updateEntities();
    this->updateBullets();
    this->generateEnemies(this->difficulty + 1);
}

void World::Draw(Game *game)
{
    this->drawBullets();
    this->drawEntities();


    Console::setCursorPosition(0,0);
}


