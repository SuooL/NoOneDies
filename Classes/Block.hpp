//
//  Block.hpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/14.
//
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class Block:public Sprite{
public:
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(Block);
};

#endif /* Block_hpp */
