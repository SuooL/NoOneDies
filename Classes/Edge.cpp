//
//  Edge.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/14.
//
//

#include "Edge.hpp"

bool Edge::init(){
    Node::init();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setAnchorPoint(Vec2(0.5f,0.5f));
    setContentSize(visibleSize);
    auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);
    body->getShape(0)->setRestitution(0);
    setPhysicsBody(body);
    return true;
}