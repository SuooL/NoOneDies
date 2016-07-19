//
//  Block.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/14.
//
//

#include "Block.hpp"

bool Block::init(){
    Sprite::init();
    Size size = Size(rand()%20+10,rand()%30+15);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setTextureRect(Rect(0,0,size.width,size.height));
    setContentSize(size);
    setColor(Color3B(0,0,0));
    setPositionX(visibleSize.width);
    setPhysicsBody(PhysicsBody::createBox(size));
    getPhysicsBody()->setDynamic(false);
    scheduleUpdate();
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
}

void Block::update(float dt){
    this->setPositionX(getPositionX()-5);
    if (getPositionX()<0) {
        unscheduleUpdate();
        removeFromParent();
    }
}