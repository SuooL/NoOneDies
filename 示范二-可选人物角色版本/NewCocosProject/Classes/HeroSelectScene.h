#ifndef _HERO_SELECT_
#define _HERO_SELECT_
#include <cocos2d.h>
#include "Hero.h"
#include "HelloWorldScene.h"
#include "GameContext.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;

class HeroSelect :public LayerColor {

private:
	Size visibleSize;

public:
	virtual bool init();

	CREATE_FUNC(HeroSelect);
	static Scene* createScene();
};
#endif