#include "HeroSelectScene.h"

USING_NS_CC;


Scene* HeroSelect::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	// 'layer' is an autorelease object
	auto layer = HeroSelect::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


bool HeroSelect::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//添加英雄模型选项
	auto hero0 = Hero::create(0);
	hero0->setPosition(Vec2(visibleSize.width / 4, visibleSize.height * 3 / 4));
	auto hero1 = Hero::create(1);
	hero1->setPosition(Vec2(visibleSize.width * 2 / 4, visibleSize.height * 3 / 4));
	auto hero2 = Hero::create(2);
	hero2->setPosition(Vec2(visibleSize.width * 3 / 4, visibleSize.height * 3 / 4));

	addChild(hero0);
	addChild(hero1);
	addChild(hero2);

	//显示有多少个英雄进入游戏
	for (int i = 0; i < GameContext::heroNum; i++)
	{
		auto heroN = Hero::create(1);
		heroN->setPosition(Vec2(visibleSize.width*(i + 1) / 5, visibleSize.height / 4));
		addChild(heroN);
	}

	//为选择英雄添加点击事件
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [hero0, hero1, hero2, visibleSize, this](Touch * t, Event * e) {
		if (hero0->getBoundingBox().containsPoint(t->getLocation()))
		{
			if (GameContext::voice)
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
			}
			GameContext::heroType = 0;
			Director::getInstance()->replaceScene(HelloWorld::createScene());
			return false;
		}
		else
			if (hero1->getBoundingBox().containsPoint(t->getLocation()))
			{
				if (GameContext::voice)
				{
					CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
				}
				GameContext::heroType = 1;
				Director::getInstance()->replaceScene(HelloWorld::createScene());
				return false;
			}
			else
				if (hero2->getBoundingBox().containsPoint(t->getLocation()))
				{
					if (GameContext::voice)
					{
						CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
					}
					GameContext::heroType = 2;
					Director::getInstance()->replaceScene(HelloWorld::createScene());
					return false;
				}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
	return true;
}
