#ifndef _PLAYER_H
#define _PLAYER_H
#include <vector>
#include "entity.h"

class Player : public Entity
{
private:
    int score;
    int previousNumberOfEntities;
public:
    Player(int x, int y, char picture, World *world);
    ~Player();
    void action();
    void Draw();
    void Update();
    void HandleEvents();
    int getScore();
    void increaseScore(int value);
    void changeScoreIfEntitiesChanged();
    void fire();
    void DrawHud();
};
#endif
