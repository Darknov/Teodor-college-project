#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "state.h"


class TestState : public State
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static TestState* Instance() {
		return &m_TestState;
	}

protected:
	TestState() { }

private:
	static TestState m_TestState;

};

#endif // TESTSTATE_H
