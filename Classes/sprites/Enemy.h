/*
 * Enemy.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "cocos2d.h"
#include "../config/EnemyType.h"

class Enemy: public cocos2d::CCSprite {
	CREATE_FUNC(Enemy)
	;

CC_PROPERTY(unsigned int , eID , EId)
	;CC_PROPERTY(unsigned int , enemyType, EnemyType)
	;CC_PROPERTY(bool, active, Active)
	;CC_PROPERTY(unsigned int , speed, Speed)
	;CC_PROPERTY(signed int , bulletSpeed, BulletSpeed)
	;CC_PROPERTY(unsigned int , HP, HP)
	;CC_PROPERTY(unsigned int , bulletPowerValue, BulletPowerValue)
	;CC_PROPERTY(unsigned int , scoreValue, ScoreValue)
	;CC_PROPERTY(unsigned int , zOrder, ZZOrder)
	;CC_PROPERTY(float , delayTime, DelayTime)
	;CC_PROPERTY(ENEMY_MOVE_TYPE , moveType, MoveType)
	;CC_PROPERTY(ENEMY_ATTACK_MODE , attackMode, AttackMode)
	;CC_PROPERTY(unsigned int, _hurtColorLife , HurtColorLife)
	;

	void ctor(EnemyType* enemy);
	void shoot();

	void update();
	void destroy();
};

#endif /* ENEMY_H_ */
