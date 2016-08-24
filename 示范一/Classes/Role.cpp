//
//  Role.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/14.
//
//

#include "Role.hpp"
#include "FlashTool.hpp"

bool Role::init(){
    Sprite::init();
    Size s = Size(44,52);
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Role.json", 0.2f)));
    setContentSize(s);
    setScale(0.6f);
    setPhysicsBody(PhysicsBody::createBox(s));
    getPhysicsBody()->setRotationEnable(false);
    getPhysicsBody()->setContactTestBitmask(1);
    return true;
}