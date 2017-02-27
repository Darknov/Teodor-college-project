#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <fstream>

class Scoreboard
{
    public:
        static void drawScoreBoard();
        static void updateScoreBoard(int score);
    protected:

    private:
        bool checkIfScoreboardExists();
};

#endif
