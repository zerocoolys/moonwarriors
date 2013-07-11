/*
 * GameMaster.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "GameMaster.h"
#include "GameConfig.h"
#include "LayerMacros.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

GameMaster::GameMaster() {
	g_hideSpritePos = ccp(-10,-10);
}

GameMaster::~GameMaster() {
}

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

GameMaster* s_GameMaster = NULL;

GameMaster* GameMaster::sharedGameMaster() {
	if (!s_GameMaster) {
		s_GameMaster = new GameMaster();
	}
	return s_GameMaster;
}

CCArray* GameMaster::getEnemies() {
	INIT_ARRAY(ENEMIES);
	return ENEMIES;
}

void GameMaster::setEnemies(CCArray* array) {
	ENEMIES = array;
}

CCArray* GameMaster::getEnemiesBullets() {
	INIT_ARRAY(ENEMIES_BULLETS);
	return ENEMIES_BULLETS;
}

void GameMaster::setEnemiesBullets(CCArray* array) {
	ENEMIES_BULLETS = array;
}

CCArray* GameMaster::getHits() {
	INIT_ARRAY(HITS);
	return HITS;
}

void GameMaster::setHits(CCArray* array) {
	HITS = array;
}

CCArray* GameMaster::getPlayerBullets() {
	INIT_ARRAY(PLAYER_BULLETS);
	return PLAYER_BULLETS;
}

void GameMaster::setPlayerBullets(CCArray* array) {
	PLAYER_BULLETS = array;
}
