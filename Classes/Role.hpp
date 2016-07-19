//
//  Role.hpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/14.
//
//

#ifndef Role_hpp
#define Role_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class Role:public Sprite{
public:
    virtual bool init();
    CREATE_FUNC(Role);
};

#endif /* Role_hpp */
