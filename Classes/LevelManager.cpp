/*
 * LevelManager.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "LevelManager.h"
#include "GameConfig.h"

using namespace cocos2d;

void LevelManager::addEnemyToGameLayer(unsigned int enemyType) {
	EnemyType* enemyTypes = EnemyType::getAllEnemyType();
	EnemyType type = enemyTypes[enemyType];

	CCPoint enemypos = ccp(80+ (winSize.width - 160) * rand(), winSize.height );

//	type.
}
