#ifndef TEST_GAMESTATE_H
#define TEST_GAMESTATE_H


#include<string>
class GameState
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    virtual std::string getStateID() const = 0;
};


#endif //TEST_GAMESTATE_H
