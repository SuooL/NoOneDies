//
//  MainScene.hpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class MainScene:public LayerColor{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
    static void playEffect();
};


#endif /* MainScene_hpp */
