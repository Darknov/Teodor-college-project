
#include <iostream>
#include <stdlib.h>

#include "game.h"
#include "state.h"
#include "menustate.h"
#include "playstate.h"
#include "console.h"
#include "scoreboard.h"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
    Console::ClearScreen();
    Console::Draw("================",0,0);
    Console::Draw("==== Teodor ====",0,1);
    Console::Draw("================",0,2);
    Console::Draw("1. Start game",1,3);
    Console::Draw("2. Scoreboard",1,4);
    Console::Draw("3. Exit",1,5);
    Console::Draw("================",0,6);
}

void MenuState::Cleanup()
{


}

void MenuState::Pause()
{

}

void MenuState::Resume()
{

}

void MenuState::HandleEvents(Game* game)
{
    if(GetAsyncKeyState('1'))
    {
        game->ChangeState( PlayState::Instance() );
    }

    if(GetAsyncKeyState('2'))
    {
        Scoreboard::drawScoreBoard();
        Sleep(1000);
    }

    if(GetAsyncKeyState('3'))
    {
        game->Quit();
    }

    if(GetAsyncKeyState('B'))
    {
        Console::ClearScreen();
        Console::Draw("================",0,0);
        Console::Draw("==== Teodor ====",0,1);
        Console::Draw("================",0,2);
        Console::Draw("1. Start game",1,3);
        Console::Draw("2. Scoreboard",1,4);
        Console::Draw("3. Exit",1,5);
        Console::Draw("================",0,6);
        Sleep(1000);

    }
}

void MenuState::Update(Game* game)
{

}

void MenuState::Draw(Game* game)
{


}
