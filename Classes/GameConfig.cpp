/*
 * GameConfig.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "GameConfig.h"

bool GameConfig::sound = true;

const int GameConfig::LIFEUP_SOURCE[] = { 50000, 100000 };

bool GameConfig::getSound() {
	return GameConfig::sound;
}
void GameConfig::setSound(bool sound) {
	GameConfig::sound = sound;
}

void GameConfig::changeSound() {
	GameConfig::sound = !GameConfig::sound;
}

//void GameConfig::initArray() {
//	GameMaster::sharedGameMaster()->setCCArray::create();
//	ENEMIES_BULLETS = CCArray::create();
//	PLAYER_BULLETS = CCArray::create();
//	HITS = CCArray::create();
//
//}

