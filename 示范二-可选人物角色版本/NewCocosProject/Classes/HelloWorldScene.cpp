#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;


Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{


	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//������Ϸ��������
	if (GameContext::voice)
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(BACKGROUND_VOICE);

	//�����ʾ�ɼ���LABEL
	label = Label::create();
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 4 / 5));
	label->setColor(Color3B::BLACK);
	label->setSystemFontSize(20);
	label->setString("SCORE          S           ");
	addChild(label);

	label = Label::create();
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 4 / 5));
	label->setColor(Color3B::RED);
	label->setSystemFontSize(20);
	label->setString("0");
	addChild(label);

	//���Ӣ��
	for (int i = 0; i < GameContext::heroNum; i++) {
		gcs.insert(0, GameController::create(this, i, GameContext::heroType));
	}
	scheduleUpdate();

	//��ʼ���ɼ�
	time = 0;
	//������ǰ�ɼ�ˢ��
	this->schedule(schedule_selector(HelloWorld::timer), 0.1f);


	//��Ӳٿ�Ӣ�۵ĵ���¼�
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact & contact) {
		this->unscheduleUpdate();
		if (GameContext::voice)
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		GameContext::score = "SCORE " + label->getString() + " S";
		Director::getInstance()->replaceScene(GameOver::createScene());
		this->unschedule(schedule_selector(HelloWorld::timer));
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [visibleSize, this](Touch * t, Event * e) {

		for (auto it = gcs.begin(); it != gcs.end(); it++) {
			if ((*it)->hitTestPoint(t->getLocation())) {
				(*it)->onUserTouch();
				break;
			}
		}

		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}


void HelloWorld::update(float dt) {

	for (auto it = gcs.begin(); it != gcs.end(); it++) {
		(*it)->onUpdate(dt);
	}

}
/**
* ˢ�µ�ǰ�ɼ��ĺ�����
*/
void HelloWorld::timer(float dt)
{
	time += 0.1f;
	char *s = new char[10];
	sprintf(s, "%.1f", time);
	std::string str = s;
	label->setString(str);
}