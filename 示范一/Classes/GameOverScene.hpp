//
//  GameOver.hpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class GameOver:public LayerColor{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameOver);
};

#endif /* GameOver_hpp */
