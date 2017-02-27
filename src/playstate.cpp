
#include <iostream>
#include <conio.h>

#include "state.h"
#include "game.h"
#include "console.h"
#include "playstate.h"
#include "menustate.h"



PlayState PlayState::m_PlayState;

void PlayState::Init()
{
	Console::ClearScreen();
	this->world = new World(1,40,30);

}

void PlayState::Cleanup()
{


}

void PlayState::Pause()
{

}

void PlayState::Resume()
{

}

void PlayState::HandleEvents(Game* game)
{
    this->world->HandleEvents(game);

}

void PlayState::Update(Game* game)
{
    this->world->Update(game);
}

void PlayState::Draw(Game* game)
{
    if(!this->world->isPlayerDead)
        this->world->Draw(game);
    else
        this->endScreen(game);
    Sleep(game->sleep);
}


void PlayState::endScreen(Game* game)
{
    Console::ClearScreen();
    Console::Draw("YOU LOSE!", 6,6);
    Sleep(3000);
    game->Quit();
}
