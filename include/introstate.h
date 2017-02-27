
#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "intro.h"
#include "state.h"

class IntroState : public State
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static IntroState* Instance() {
		return &m_IntroState;
	}

protected:
	IntroState() { }

private:
	static IntroState m_IntroState;
    Intro *intro;

	int alpha;
};

#endif
