//
//  GameController.cpp
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#include "GameController.h"


GameController* GameController::create(cocos2d::Layer *layer, float positionY, int heroType) {

	auto _ins = new GameController();
	_ins->init(layer, positionY, heroType);
	_ins->autorelease();
	return _ins;
}


bool GameController::init(cocos2d::Layer *layer, float positionY, int heroType) {

	_layer = layer;
	visibleSize = Director::getInstance()->getVisibleSize();
	_positionY = 30 + visibleSize.height*positionY / 5;
	//add edge
	edge = Edge::create();
	edge->setPosition(visibleSize.width / 2, edge->getContentSize().height / 2 + _positionY);
	layer->addChild(edge);

	//add ground
	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground->setPosition(visibleSize.width / 2, 1.5 + _positionY);
	layer->addChild(ground);

	//add hero
	hero = Hero::create(heroType);
	hero->setPosition(50, hero->getContentSize().height / 2 + _positionY);
	layer->addChild(hero);


	resetFrames();
	return true;
}

void GameController::resetFrames() {
	currentFrameIndex = 0;
	nextFrameCount = (rand() % 120) + 100;
}


void GameController::addBlock() {
	auto b = Block::create();
	_layer->addChild(b);
	b->setPositionY(b->getContentSize().height / 2 + _positionY);
}


void GameController::onUpdate(float dt) {
	currentFrameIndex++;

	if (currentFrameIndex >= nextFrameCount) {
		resetFrames();

		addBlock();
	}
}

bool GameController::hitTestPoint(cocos2d::Vec2 point) {
	
	//计算该英雄当前的离地高度
	auto sit = point + edge->getContentSize() / 2;
	auto y1 = hero->getPositionY() - hero->getContentSize().height / 2;
	auto y2 = edge->getPositionY() - edge->getContentSize().height / 2;
	auto y3 = y1 - y2;

	//如果离地高度小于10.且点击范围在该英雄范围内。
	if (y3< 10 && point.y>y1 && point.y < y1 + visibleSize.height / 5) {
		return true;
	}
	return false;
}

void GameController::onUserTouch() {
	hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}
