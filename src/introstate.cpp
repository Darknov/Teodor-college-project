#include <iostream>
#include "game.h"
#include "state.h"
#include "introstate.h"
#include "playstate.h"
#include "teststate.h"
#include "menustate.h"

IntroState IntroState::m_IntroState;



void IntroState::Init()
{
    this->intro = new Intro("Teodor.logo");
}

void IntroState::Cleanup()
{

	delete this->intro;
}

void IntroState::Pause()
{

}

void IntroState::Resume()
{

}

void IntroState::HandleEvents(Game* game)
{
    if(GetAsyncKeyState(VK_SPACE))
    {
        game->ChangeState( MenuState::Instance() );
    }
}

void IntroState::Update(Game* game)
{
    this->intro->Update();
}

void IntroState::Draw(Game* game)
{
    this->intro->Draw();
}
