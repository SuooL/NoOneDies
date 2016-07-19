//
//  GameOver.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//
#include "GameOverScene.hpp"
#include "GamePlayScene.hpp"
#include "MainScene.hpp"

USING_NS_CC;

std::string gameOverLabel[] = {"Back","Retry"};

Scene* GameOver::createScene(){
    auto scene =Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    return scene;
}

bool GameOver::init(){
    LayerColor::initWithColor(Color4B::WHITE);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    //add game over title
    auto label = Label::create();
    label->setString("Game Over");
    label->setSystemFontSize(40);
    label->setColor(Color3B::BLACK);
    addChild(label);
    label->setPosition(visibleSize.width/2,visibleSize.height-80);
    
    //add game score label
    auto gameScore = TextFieldTTF::create();
    gameScore->setString(StringUtils::format("%.4f''",GamePlayScene::gameTime));
    gameScore->setColor(Color3B::RED);
    gameScore->setSystemFontSize(70);
    gameScore->setPosition(visibleSize.width/2,visibleSize.height/2+60);
    auto scale = ScaleBy::create(0.5, 1.5);
    auto scaleReverse = scale->reverse();
    gameScore->runAction(Sequence::create(scale,scaleReverse, NULL));
    log("gameTime = %f",GamePlayScene::gameTime);
    addChild(gameScore);
    
    //add the best score label
    auto bestScore = TextFieldTTF::create();
    bestScore->setString(StringUtils::format("Best: %.4f''",UserDefault::getInstance()->getFloatForKey("best")));
    bestScore->setColor(Color3B::GRAY);
    bestScore->setSystemFontSize(30);
    bestScore->setPosition(visibleSize.width/2,visibleSize.height/2-20);
    addChild(bestScore);
    
    //add menu
    auto menu = Menu::create();
    menu->setPosition(visibleSize.width/2,visibleSize.height/4);
    int count = sizeof(gameOverLabel)/sizeof(gameOverLabel[0]);
    for (int i = 0; i<count; i++) {
        auto label = Label::create();
        label->setString(gameOverLabel[i]);
        label->setSystemFontSize(30);
        label->setColor(Color3B::BLACK);
        auto item = MenuItemLabel::create(label, [i](Object* o){
            MainScene::playEffect();
            GamePlayScene::gameTime = 0;
            if (i==0) {
                Director::getInstance()->replaceScene(MainScene::createScene());
            }else{
                Director::getInstance()->replaceScene(GamePlayScene::createScene());
            }
        });
        menu->addChild(item);
    }
    menu->alignItemsHorizontallyWithPadding(100);
    addChild(menu);
    
    //add physical button "Backspace" listener
    auto physicalButtonListener = EventListenerKeyboard::create();
    physicalButtonListener->onKeyReleased = [](EventKeyboard::KeyCode code,Event* e){
        switch (code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_BACK:
                Director::getInstance()->end();
                break;
            default:
                break;
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(physicalButtonListener, this);
    
    return true;
}



