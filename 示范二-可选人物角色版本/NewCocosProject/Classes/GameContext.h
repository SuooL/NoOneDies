
#ifndef CONTEXT_
#define CONTEXT_
#include <cocos2d.h>
#include <iostream>
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define EFFECT_FILE "effect.wav"
#define BACKGROUND_VOICE "background.mp3"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE "effect.ogg"
#define BACKGROUND_VOICE "background.ogg"
#endif

class GameContext {
public:
	static int heroNum;
	static  int heroType;
	static std::string score;
	static bool voice;
};
#endif