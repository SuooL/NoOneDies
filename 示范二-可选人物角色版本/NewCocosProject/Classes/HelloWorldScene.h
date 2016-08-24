#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameController.h"
#include "GameOverScene.h"
#include "GameContext.h"

class HelloWorld : public cocos2d::LayerColor
{
private:
	cocos2d::Vector<GameController*> gcs;
	cocos2d::Label *label;
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);

	virtual void update(float dt);

	float  time;

	void timer(float dt);
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();


};

#endif // __HELLOWORLD_SCENE_H__
