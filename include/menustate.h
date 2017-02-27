
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"

class MenuState : public State
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static MenuState* Instance() {
		return &m_MenuState;
	}

protected:
	MenuState() { }

private:
	static MenuState m_MenuState;

};

#endif