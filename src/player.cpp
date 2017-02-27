#include <player.h>
#include "bullet.h"
#include "scoreboard.h"
Player::~Player()
{

}

Player::Player(int x, int y, char picture, World *world): Entity(x,y,picture,world)
{
    this->hp = 10;
    this->score = 0;
}

void Player::action()
{




    if(GetAsyncKeyState(VK_UP) && (this->getY() > 1))
    {
        this->picture = 24;
        this->move('w');
    }
    else if(GetAsyncKeyState(VK_DOWN) && (this->getY() < this->world->getY() - 2))
    {
        this->picture = 25;
        this->move('s');
    }
    else if(GetAsyncKeyState(VK_LEFT) && (this->getX() > 1))
    {
        this->picture = 27;
        this->move('a');
    }
    else if(GetAsyncKeyState(VK_RIGHT) && (this->getX() < this->world->getX() - 2))
    {
        this->picture = 26;
        this->move('d');
    }

    if(GetAsyncKeyState(VK_SPACE))
    {
        this->fire();
    }

}

void Player::changeScoreIfEntitiesChanged()
{
    if(this->world->getEntityNumber() < this->previousNumberOfEntities)
    {
        this->score += 1;
    }

    if(this->world->getEntityNumber() > this->previousNumberOfEntities)
    {
        this->score += 1;
    }
}

void Player::fire()
{
        switch(this->lastKey)
        {
        case 's':
            if(this->y == this->world->getY() - 2)
                break;
            this->world->pushBullet(new Bullet(this->getX(),this->getY()+1,5.0,'o',this->lastKey,this->world));
            break;
        case 'a':
            if(this->x == 1)
                break;
            this->world->pushBullet(new Bullet(this->getX()-1,this->getY(),5.0,'o',this->lastKey,this->world));
            break;
        case 'w':
            if(this->y == 1)
                break;
            this->world->pushBullet(new Bullet(this->getX(),this->getY()-1,5.0,'o',this->lastKey,this->world));
            break;
        case 'd':
            if(this->x == this->world->getX() - 2)
                break;
            this->world->pushBullet(new Bullet(this->getX()+1,this->getY(),5.0,'o',this->lastKey,this->world));
            break;
        default:;
        }
}

void Player::DrawHud()
{
    Console::Draw("       ",12,this->world->getY());
    Console::Draw("Score: " + std::to_string(this->score),5,this->world->getY());

    Console::Draw("       ",20,this->world->getY());
    Console::Draw("HP: " + std::to_string(this->hp),15,this->world->getY());

}

void Player::HandleEvents()
{
    this->action();
}

void Player::Draw()
{
    Console::Draw(' ',this->previousX,this->previousY);
    Console::Draw(this->getPicture(),this->getX(),this->getY());
    this->DrawHud();

}

void Player::Update()
{
    this->changeScoreIfEntitiesChanged();
    this->previousNumberOfEntities = this->world->getEntityNumber();
    this->checkIfBulletHit();
    if(this->hp <= 0)
    {
        this->Draw();
        Scoreboard::updateScoreBoard(this->score);
    }
}

int Player::getScore()
{
    return this->score;
}

void Player::increaseScore(int value)
{
    this->score += value;
}
