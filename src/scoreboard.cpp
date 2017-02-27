#include "scoreboard.h"
#include <vector>
#include <string>
#include <console.h>

Scoreboard scoreboard;

void Scoreboard::drawScoreBoard()
{
    if(scoreboard.checkIfScoreboardExists())
    {
        std::ifstream f("Scoreboard");
        std::vector<std::string> scores;
        std::string line;
        if (f)
        {
            while (getline( f, line ))
            {
                scores.push_back(line);
            }
            f.close();
        }
        Console::ClearScreen();
        int i = 1;
        Console::SlowWriting("Scoreboard", 0,0, 50 );
        for(auto& it : scores){

            Console::SlowWriting(std::to_string(i) + ". " + it, 0 , i,50);
            i++;
        }

        Console::SlowWriting("Click b to back to the menu.", 0,i,30 );


    }
    else
    {
        std::ofstream f("Scoreboard");
        f.close();
    }
}

void Scoreboard::updateScoreBoard(int score)
{
    if(scoreboard.checkIfScoreboardExists())
    {
        std::ifstream f("Scoreboard");
        std::vector<std::string> scores;
        std::string line;
        bool isSaved = false;
        int v = 0;
        if (f)
        {
            while (getline( f, line ))
            {
                if(std::stoi(line) < score && !isSaved)
                {
                    scores.push_back(std::to_string(score));
                    isSaved = true;
                }
                scores.push_back(line);
            }
            if(!isSaved)
            {
                scores.push_back(std::to_string(score));
            }

            f.close();
        }

        std::ofstream fo("Scoreboard");
        if(fo)
        {
            for(auto& it : scores)
            {
                fo << it + "\n";
                v++;
                if(v==10)
                    break;
            }
        }



        fo.close();
    }
    else
    {
        std::ofstream f("Scoreboard");
        f.close();
    }
}

bool Scoreboard::checkIfScoreboardExists()
{
    std::ifstream f("Scoreboard");
    return f.good();
}
