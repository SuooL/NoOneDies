//
//  Controller.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//

#include "Controller.hpp"
#include "MainScene.hpp"

Controller* Controller::create(cocos2d::Layer *layer, float positionY){
    auto _ins = new Controller();
    _ins->init(layer, positionY);
    _ins->autorelease();
    return _ins;
}

bool Controller::init(cocos2d::Layer * layer,float positionY){
    
    _layer = layer;
    _positionY = positionY;
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //add edge;
    edge = Edge::create();
    edge->setPosition(visibleSize.width/2,visibleSize.height/2+positionY);
    _layer->addChild(edge);
    
    //add role;
    role = Role::create();
    role->setPosition(50,role->getContentSize().height/2+positionY);
    _layer->addChild(role);
    
    //add ground
    auto ground = Sprite::create();
    ground->setColor(Color3B(0,0,0));
    ground->setTextureRect(Rect(0,0,visibleSize.width,3));
    ground->setPosition(visibleSize.width/2,1.5+positionY);
    _layer->addChild(ground);
    
    //reset frames
    resetFrames();
    return true;
}

//reset frames
void Controller::resetFrames(){
    currentFrameIndex = 0;
    nextFrameCount = rand()%120 + 100;
}

//when currentFrame++ > nextFrame, add a block
void Controller::onUpdate(float dt){
    currentFrameIndex++;
    if (currentFrameIndex>=nextFrameCount) {
        resetFrames();
        addBlock();
    }
}

//add block
void Controller::addBlock(){
    auto b = Block::create();
    _layer->addChild(b);
    b->setPositionY(b->getContentSize().height/2+_positionY);
}

//get edge bounding and distinguish user touching range
bool Controller::hitTestPoint(cocos2d::Vec2 point){
    return edge->getBoundingBox().containsPoint(point);
}

//hero jump
void Controller::onUserTouch(){
    auto value = Value(role->getPhysicsBody()->getVelocity().y);
    if (value.asInt()==0) {
        MainScene::playEffect();
        role->getPhysicsBody()->setVelocity(Vec2(0,350));
    }
}

