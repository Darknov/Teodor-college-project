#include "map.h"
#include <vector>
#include "iostream"
#include "console.h"

Map::Map(int x, int y)
    :x(x),y(y)
{
    for(int i = 0; i < y; i++)
    {
        std::vector<char> temp;
        for(int j = 0; j < x; j++)
        {
            temp.push_back(' ');
        }
        this->board.push_back(temp);
    }


    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            if(i==0 || i == this->y-1)
            {
                this->board[i][j] = '#';
            }

            if(j==0 || j == this->x-1)
            {
                this->board[i][j] = '#';
            }
        }
    }



}

int Map::getX()
{
    return this->x;
}

int Map::getY()
{
    return this->y;
}

void Map::Draw()
{
    Console::Draw(this);
}
