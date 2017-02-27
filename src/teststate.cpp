#include <iostream>

#include "game.h"
#include "state.h"
#include "teststate.h"

TestState TestState::m_TestState;

void TestState::Init()
{
	std::cout <<"TestState Init\n"<<std::endl;
}

void TestState::Cleanup()
{

	std::cout <<"TestState Cleanup\n"<<std::endl;
}

void TestState::Pause()
{
	std::cout <<"TestState Pause\n"<<std::endl;
}

void TestState::Resume()
{
	std::cout <<"TestState Resume\n"<<std::endl;
}

void TestState::HandleEvents(Game* game)
{

}

void TestState::Update(Game* game)
{

}

void TestState::Draw(Game* game)
{

}
