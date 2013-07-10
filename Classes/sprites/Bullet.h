/*
 * Bullet.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "cocos2d.h"
#include "../GameType.h"

class Bullet: public cocos2d::CCSprite {

	CREATE_FUNC(Bullet)
	;CC_PROPERTY(bool,active,Active)
	;CC_PROPERTY(unsigned int,xVelocity,XVelocity)
	;CC_PROPERTY(unsigned int,yVelocity,YVelocity)
	;CC_PROPERTY(unsigned int,power,Power)
	;CC_PROPERTY(unsigned int,HP,HP)
	;CC_PROPERTY(ENEMY_MOVE_TYPE,moveType,MoveType)
	;CC_PROPERTY(ENEMY_ATTACK_MODE,attackMode,AttackMode)
	;CC_PROPERTY(unsigned int,zOrder,ZZOrder)
	;CC_PROPERTY(BulletType, parentType, ParentType)
	;

public:
	void ctor(unsigned int bulletSpeed, WeaponType weaponType,
			EnemyAttackMode attackMode);
	void update(float dt);
	void destroy();
	void hurt();
	void collideRect(cocos2d::CCPoint point);
};

#endif /* BULLET_H_ */
