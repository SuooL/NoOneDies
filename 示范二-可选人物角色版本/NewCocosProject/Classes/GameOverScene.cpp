#include "GameOverScene.h"


bool GameOver::init() {
	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	//����������ʾ�ɼ��Ŀؼ�
	auto label = Label::create();
	label->setString(GameContext::score);
	label->setSystemFontSize(30);
	label->setColor(Color3B::RED);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 4);

	//����������ʾGAMEOVER��label
	label = Label::create();
	label->setString("Game Over");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	//���ذ�ť
	auto back = Sprite::create("restart.png");
	back->setPosition(visibleSize.width / 4, visibleSize.height / 4);
	addChild(back);

	//�˳���ť
	auto exit = Sprite::create("exit.png");
	exit->setPosition(visibleSize.width * 3 / 4, visibleSize.height / 4);
	addChild(exit);

	//Ϊ��ť����¼�
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [back, exit, this](Touch * t, Event * e) {
		if (back->getBoundingBox().containsPoint(t->getLocation()))
		{	
			//���¿�ʼ
			if (GameContext::voice)
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
			Director::getInstance()->replaceScene(GameStart::createScene());
		}
		if (exit->getBoundingBox().containsPoint(t->getLocation()))
		{
			//�˳�
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
