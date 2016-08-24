#ifndef _GAME_START_
#define _GAME_START_

#include <cocos2d.h>
#include "HeroSelectScene.h"
#include "GameContext.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class GameStart :public LayerColor {

private:
	Size visibleSize;

public:
	virtual bool init();

	CREATE_FUNC(GameStart);
	static Scene* createScene();
};
#endif
