#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Controller.hpp"

#define DEGREE_EASY 1
#define DEGREE_NORMAL 2
#define DEGREE_HARD 3
#define DEGREE_HELL 4

class GamePlayScene : public cocos2d::LayerColor
{
private:
    cocos2d::Vector<Controller*> cs;
    Label * label;
    //second of game time
    float timeSecond;
    //minute of game time
    float timeMinute;
    Size visibleSize;
private:
    //reset game time
    void resetGameTime();
    //game time counter
    void gameTimeCounter(float dt);
    //degree chooser
    void gamePlayer(int degree);
    
public:
    //game time counter
    static float gameTime;
    //degree value
    static int _degree;
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void update(float dt);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayScene);
};

#endif // __HELLOWORLD_SCENE_H__
