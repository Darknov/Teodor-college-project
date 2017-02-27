
#ifndef STATE_H
#define STATE_H

#include "game.h"

class State
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(Game* game) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Draw(Game* game) = 0;

	void ChangeState(Game* game, State* state) {
		game->ChangeState(state);
	}

protected:
	State() { }
};

#endif
