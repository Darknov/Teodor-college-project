#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map
{
public:
    std::vector< std::vector<char> > board;
    Map(int x,int y);
    int getX();
    int getY();
    void Draw();
private:
    int x,y;


};


#endif
