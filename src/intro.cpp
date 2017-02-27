#include "intro.h"
#include "console.h"
#include <iostream>

bool isOn = true;

Intro::Intro(std::string pathToIntro)
{
    Console::setCursorPosition(0,0);
    std::string line;
    std::ifstream myfile( pathToIntro );
    if (myfile)
    {
        while (getline( myfile, line ))
        {
            this->logo.push_back(line);
        }
        myfile.close();
    }


    for(auto& it : this->logo){
        std::cout << it << std::endl;
    }
}

void Intro::Draw()
{
    Console::setCursorPosition(10,10);
    if(isOn)
        std::cout << "CLICK SPACE TO START";
    else
        std::cout << "                    ";
    Console::setCursorPosition(0,0);

}

void Intro::Update()
{
    isOn = !isOn;
    Sleep(1000);
}
