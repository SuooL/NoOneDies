#include "GamePlayScene.hpp"
#include "SimpleAudioEngine.h"
#include "GameOverScene.hpp"

USING_NS_CC;

int GamePlayScene::_degree = 0;
float GamePlayScene::gameTime = 0;

Scene* GamePlayScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    //set gravity
    scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    
    // 'layer' is an autorelease object
    auto layer = GamePlayScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GamePlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    //set Background color
    if ( !LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //choose degree and start playing
    gamePlayer(GamePlayScene::_degree);
    
    //label show time
    label = Label::create();
    label->setSystemFontSize(26);
    label->setColor(Color3B::BLACK);
    label->setPosition(visibleSize.width-60,visibleSize.height-20);
    addChild(label);
    
    //reset game time counter
    resetGameTime();
    //start counting game time
    schedule(schedule_selector(GamePlayScene::gameTimeCounter),0.01f,kRepeatForever,0);
    
    //add contact listener
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [this](PhysicsContact & contact){
        this->unscheduleUpdate();
        //get game time, compare with game best time
        auto best = UserDefault::getInstance()->getFloatForKey("best");
        if (gameTime>best) {
            UserDefault::getInstance()->setFloatForKey("best", gameTime);
        }
        //replace game over scene
        Director::getInstance()->replaceScene(GameOver::createScene());
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //add user touch listener
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch * t,Event * e){
        for (auto it = cs.begin(); it!=cs.end(); it++) {
            if ((*it)->hitTestPoint(t->getLocation())) {
                //hero jump
                (*it)->onUserTouch();
                break;
            }
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

//update blocks
void GamePlayScene::update(float dt){
    for (auto it = cs.begin(); it!=cs.end(); it++) {
        (*it)->onUpdate(dt);
    }
}

//choose degree and start playing
void GamePlayScene::gamePlayer(int d){
    float h = (visibleSize.height-20)/d;
    //get degree from user selected
    for (auto i = 0; i<d; i++) {
        cs.insert(0, Controller::create(this, 30+h*i));
    }
    //start playing
    scheduleUpdate();
}

//update label of game time
void GamePlayScene::gameTimeCounter(float dt){
    timeSecond+=0.01f;
    if (timeSecond>=60) {
        timeMinute++;
        timeSecond=0;
    }
    //get current game time
    gameTime =timeMinute+(timeSecond/100);
    //update label
    label->setString(StringUtils::format("%.4f''",gameTime));
}

//reset game time
void GamePlayScene::resetGameTime(){
    timeSecond = 0;
    timeMinute = 0;
}


void GamePlayScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
