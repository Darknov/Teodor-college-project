#ifndef INTRO_H
#define INTRO_H
#include <fstream>
#include <vector>
#include <string>

class Intro
{
    public:
        Intro(std::string pathToIntro);
        void Draw();
        void Update();

    protected:

    private:
        std::vector<std::string> logo;
};

#endif // INTRO_H
