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
	GameMaster();
	~GameMaster();

	CCPoint g_hideSpritePos;

	static CCSprite* getBackground();
	static CCSprite* getBackground(const CCPoint& point);
	static void playBackgroundMusicLoop(const char* fileName);
	static void playBackgroundMusicOneTime(const char* fileName);
	static void playEffectLoop(const char* fileName);
	static void playEffectOneTime(const char* fileName);

//	CCArray* ENEMIES;
//		CCArray* ENEMIES_BULLETS;
//		CCArray* PLAYER_BULLETS;
//		CCArray* HITS;
	static GameMaster* sharedGameMaster();

CC_PROPERTY(CCArray*,ENEMIES, Enemies)
	;CC_PROPERTY(CCArray*,ENEMIES_BULLETS, EnemiesBullets)
	;CC_PROPERTY(CCArray*,PLAYER_BULLETS, PlayerBullets)
	;CC_PROPERTY(CCArray*,HITS, Hits)
	;
};

#endif /* GAMEMASTER_H_ */
