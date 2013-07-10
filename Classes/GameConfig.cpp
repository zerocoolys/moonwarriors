/*
 * GameConfig.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "GameConfig.h"

bool GameConfig::sound = true;

CCArray* GameConfig::ENEMIES;
CCArray* GameConfig::ENEMIES_BULLETS;
CCArray* GameConfig::PLAYER_BULLETS;
CCArray* GameConfig::HITS;

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

void GameConfig::initArray() {
	GameConfig::ENEMIES = CCArray::create();
	GameConfig::ENEMIES_BULLETS = CCArray::create();
	GameConfig::PLAYER_BULLETS = CCArray::create();
	GameConfig::HITS = CCArray::create();

}

