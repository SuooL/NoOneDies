//
//  Hero.cpp
//  NoOneDies
//
//  Created by plter on 14-6-2.
//
//

#include "Hero.h"
#include "FlashTool.h"

Hero* Hero::create(int heroType) {

	auto _ins = new Hero();
	_ins->init(heroType);
	_ins->autorelease();
	return _ins;
}

bool Hero::init(int heroType) {
	Sprite::init();

	Size s = Size(44, 52);
	if (heroType == 0)
		runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("HeroGirl.json", 0.2f)));
	else
		if (heroType == 1)
			runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("HeroRed.json", 0.2f)));
		else
			runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));
	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));

	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1);

	return true;
}