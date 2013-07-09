/*
 * GameMaster.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "GameMaster.h"
#include "GameConfig.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCSprite* GameMaster::getBackground() {
	CCSprite* sp = CCSprite::create(RES_LOADING);
	sp->setAnchorPoint(ccp(0,0));
	return sp;
}

CCSprite* GameMaster::getBackground(const CCPoint& anchor) {
	CCSprite* sp = CCSprite::create(RES_LOADING);
	sp->setAnchorPoint(anchor);
	return sp;
}

void GameMaster::playBackgroundMusicLoop(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(fileName, true);
	}
}
void GameMaster::playBackgroundMusicOneTime(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(fileName, false);
	}
}

void GameMaster::playEffectLoop(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playEffect(fileName, true);
	}
}
void GameMaster::playEffectOneTime(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playEffect(fileName, false);
	}
}

