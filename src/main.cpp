
#include "game.h"
#include "introstate.h"
#include <Windows.h>
#include <ctime>



int main ( int argc, char *argv[] )
{
    srand((time(NULL)));
	Game game;

	// initialize the engine
	game.Init( "Teodor alfa beta gamma v0.01" );

	// load the intro
	game.ChangeState( IntroState::Instance() );

	// main loop
	while ( game.Running() )
	{

		game.HandleEvents();
		game.Update();
        game.Draw();

	}

	// cleanup the engine
	game.Cleanup();

	return 0;
}
