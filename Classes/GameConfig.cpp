/*
 * GameConfig.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "GameConfig.h"

bool sound = true;

bool GameConfig::getSound() {
	return sound;
}
void GameConfig::setSound(bool sound) {
	sound = sound;
}

void GameConfig::changeSound(){
	sound = !sound;
}

