#include "GameStartScene.h"
USING_NS_CC;



Scene* GameStart::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// 'layer' is an autorelease object
	auto layer = GameStart::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameStart::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//加载音效
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(EFFECT_FILE);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BACKGROUND_VOICE);

	//添加标题和选项图片
	auto sprite = Sprite::create("start.png");
	sprite->setPosition(visibleSize / 2);
	addChild(sprite);

	//添加音效控制开关
	auto voice = Sprite::create("speaker.png");
	voice->setPosition(visibleSize.width - voice->getContentSize().width, visibleSize.height - voice->getContentSize().height);
	addChild(voice);
	if (GameContext::voice)
	{
		voice->setVisible(true);
	}
	else
	{
		voice->setVisible(false);
	}
	auto voice1 = Sprite::create("speaker_1.png");
	voice1->setPosition(visibleSize.width - voice->getContentSize().width, visibleSize.height - voice->getContentSize().height);
	addChild(voice1);
	if (GameContext::voice)
	{
		voice1->setVisible(false);
	}
	else
	{
		voice1->setVisible(true);
	}
	//退出按钮
	auto exit = Sprite::create("exit.png");
	exit->setPosition(visibleSize.width * 9/ 10, visibleSize.height /16);
	addChild(exit);

	//添加点击事件
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [voice, voice1, exit, visibleSize, this](Touch * t, Event * e) {
		auto  hitX = t->getLocation().x / visibleSize.width;
		auto  hitY = t->getLocation().y / visibleSize.height;
		if (hitX > 0.25 && hitX < 0.73)
		{
			if (hitY > 0.2 && hitY < 0.7)
			{
				if (GameContext::voice)
				{

					CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
				}
				GameContext::heroNum = 5-(hitY-0.2)*4/0.5;
				Director::getInstance()->replaceScene(HeroSelect::createScene());
			}
		}else
		if (voice->getBoundingBox().containsPoint(t->getLocation())) {
			GameContext::voice = !GameContext::voice;
			if (GameContext::voice)
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
				voice->setVisible(true);
				voice1->setVisible(false);
			}
			else
			{
				voice1->setVisible(true);
				voice->setVisible(false);
			}
		}else
			if (exit->getBoundingBox().containsPoint(t->getLocation()))
			{
				//退出
				if (GameContext::voice)
					CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
				Director::getInstance()->end();

			}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}