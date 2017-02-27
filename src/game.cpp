#include <iostream>
#include "game.h"
#include "state.h"

void Game::Init(const char* title)
{
	m_running = true;
	std::cout <<"Game Init\n"<<std::endl;
    this->sleep = 100;
}

void Game::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}



}

void Game::ChangeState(State* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(State* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void Game::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void Game::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void Game::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}
