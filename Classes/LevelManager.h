/*
 * LevelManager.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

#include "cocos2d.h"
#include "config/EnemyType.h"

class LevelManager: public cocos2d::CCObject {
public:
	CREATE_FUNC(LevelManager)
	;

	void ctor();
	void setLevel(LevelManager* levelManager);
	void loadLevelResource(const char* deltaTime);
	void addEnemyToGameLayer(EnemyType* enemyType);
private:
	void _minuteToSecond(const char* minuteStr);
};

#endif /* LEVELMANAGER_H_ */
