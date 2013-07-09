/*
 * GameMaster.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef GAMEMASTER_H_
#define GAMEMASTER_H_

#include "cocos2d.h"

using namespace cocos2d;

class GameMaster {
public:

public:
	static CCSprite* getBackground();
	static CCSprite* getBackground(const CCPoint& point);
	static void playBackgroundMusicLoop(const char* fileName);
	static void playBackgroundMusicOneTime(const char* fileName);
	static void playEffectLoop(const char* fileName);
	static void playEffectOneTime(const char* fileName);
};

typedef enum {

} RESOURCE;

#endif /* GAMEMASTER_H_ */
