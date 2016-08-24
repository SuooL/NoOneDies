//
//  Controller.hpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "Edge.hpp"
#include "Role.hpp"
#include "Block.hpp"
USING_NS_CC;

class Controller:public Ref{
private:
    Layer * _layer;
    float _positionY;
    Size visibleSize;
    int currentFrameIndex;
    int nextFrameCount;
    Edge * edge;
    Role * role;
    float rolePositionY;
    
private:
    void resetFrames();
    void addBlock();
    
public:
    virtual bool init(Layer * layer,float posisionY);
    static Controller* create(Layer * layer,float positionY);
    void onUpdate(float dt);
    bool hitTestPoint(Vec2 point);
    void onUserTouch();
    
};

#endif /* Controller_hpp */
