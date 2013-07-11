/*
 * EnemyType.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef ENEMYTYPE_H_
#define ENEMYTYPE_H_

#include "cocos2d.h"
#include "../GameType.h"

class EnemyType {
CC_PROPERTY(unsigned int, type ,Type)
	;CC_PROPERTY(char*,textureName,TextureName)
	;CC_PROPERTY(char*,bulletType,BulletType)
	;CC_PROPERTY(unsigned int, HP ,HP)
	;CC_PROPERTY(unsigned int, scoreValue ,ScoreValue)
	;CC_PROPERTY(ENEMY_MOVE_TYPE,moveType,MoveType)
	;CC_PROPERTY(ENEMY_ATTACK_MODE,attackMode,AttackMode)
	;

//	char* textureName;
//	char* bulletType;
//	unsigned int HP;
//	ENEMY_MOVE_TYPE moveType;
//	ENEMY_ATTACK_MODE attackMode;
//	unsigned int scoreValue;
public:
	EnemyType* enemies[];
	static EnemyType* getAllEnemyType();
};

#endif /* ENEMYTYPE_H_ */
