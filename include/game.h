
#ifndef GAME_H
#define GAME_H


#include "world.h"
#include "console.h"
#include <windows.h>
#include <vector>
using namespace std;

class State;

class Game
{
public:
	void Init(const char* title);
	void Cleanup();
	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();
	void HandleEvents();
	void Update();
	void Draw();
	bool Running() { return m_running; }
	void Quit() { m_running = false; }
	int sleep;


private:
	// the stack of states
	vector<State*> states;


	bool m_running;
	bool m_fullscreen;
};

#endif
