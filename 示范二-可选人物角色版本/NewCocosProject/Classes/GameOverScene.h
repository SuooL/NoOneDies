#ifndef _GAME_OVER_
#define _GAME_OVER_

#include <cocos2d.h>
#include "GameStartScene.h"
#include "GameContext.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class GameOver :public LayerColor {

private:
	Size visibleSize;

public:
	virtual bool init();
	CREATE_FUNC(GameOver);
	static Scene* createScene();
};
#endif


