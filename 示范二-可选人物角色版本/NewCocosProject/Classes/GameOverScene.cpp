#include "GameOverScene.h"


bool GameOver::init() {
	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	//创建用于显示成绩的控件
	auto label = Label::create();
	label->setString(GameContext::score);
	label->setSystemFontSize(30);
	label->setColor(Color3B::RED);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 4);

	//创建用于显示GAMEOVER的label
	label = Label::create();
	label->setString("Game Over");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	//返回按钮
	auto back = Sprite::create("restart.png");
	back->setPosition(visibleSize.width / 4, visibleSize.height / 4);
	addChild(back);

	//退出按钮
	auto exit = Sprite::create("exit.png");
	exit->setPosition(visibleSize.width * 3 / 4, visibleSize.height / 4);
	addChild(exit);

	//为按钮添加事件
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [back, exit, this](Touch * t, Event * e) {
		if (back->getBoundingBox().containsPoint(t->getLocation()))
		{	
			//重新开始
			if (GameContext::voice)
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
			Director::getInstance()->replaceScene(GameStart::createScene());
		}
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
};

Scene* GameOver::createScene() {
	auto s = Scene::create();
	auto l = GameOver::create();
	s->addChild(l);
	return s;
};
