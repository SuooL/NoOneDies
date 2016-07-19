//
//  MenuLabel.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/17.
//
//

#include "MenuLabel.hpp"

bool MenuLabel::init(){
    Label::init();
    setSystemFontSize(30);
    setColor(Color3B::BLACK);
    setSystemFontName("chalkduster");
    return true;
}