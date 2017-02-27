#include "console.h"
#include <windows.h>

void Console::Draw(char c,int positionX, int positionY)
{
    Console::setCursorPosition(positionX,positionY);
    std::cout << c;
}


void Console::Draw(std::string textLine,int positionX, int positionY)
{
    Console::setCursorPosition(positionX,positionY);
    std::cout << textLine;
}

void Console::Draw(Map *consoleMap)
{
    Console::setCursorPosition(0,0);
    for(int i = 0; i < consoleMap->getY(); i++)
    {
        for(int j = 0; j < consoleMap->getX(); j++)
        {
            std::cout << consoleMap->board[i][j];
        }
        std::cout << "\n";
    }
}

void Console::ClearScreen()
{
    for(int i = 0; i < 50; i++)
    {
        Console::Draw("                                                                                   ",0,i);
    }
    Console::setCursorPosition(0,0);
}


void Console::setCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(output, pos);
}

void Console::SlowWriting(std::string textLine,int positionX, int positionY, int slow)
{
    for(int i = 0; i < textLine.length(); i++)
    {
        Console::Draw(textLine.at(i),i+positionX,positionY);
        Sleep(slow);
    }
}
