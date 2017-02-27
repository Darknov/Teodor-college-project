#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <iostream>
#include <Windows.h>
#include "map.h"



class Console
{
    public:
        static void Draw(char c,int positionX, int positionY);
        static void Draw(std::string textLine,int positionX, int positionY);
        static void Draw(Map *consoleMap);
        static void ClearScreen();
        static void setCursorPosition(int x, int y);
        static void SlowWriting(std::string textLine,int positionX, int positionY, int slow);

    protected:

    private:


};

#endif // CONSOLE_H
