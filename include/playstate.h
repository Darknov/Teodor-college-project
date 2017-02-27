
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "world.h"

class PlayState : public State
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static PlayState* Instance() {
		return &m_PlayState;
	}

	void endScreen(Game* game);
	World* world;
	int key;

protected:
	PlayState() { }

private:
	static PlayState m_PlayState;

};

#endif
