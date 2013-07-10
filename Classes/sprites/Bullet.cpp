/*
 * Bullet.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "Bullet.h"

using namespace cocos2d;

void Bullet::ctor(unsigned int bulletSpeed, const char* weaponType,
		EnemyAttackMode attackMode) {
	this->init();

	this->setYVelocity(this->getYVelocity() - bulletSpeed);
	this->setAttackMode(attackMode);
	this->initWithSpriteFrameName(weaponType);

	ccBlendFunc blendFunc = { GL_SRC_ALPHA, GL_ONE };
	this->setBlendFunc(blendFunc);

}

void update(float dt) {

}
void destroy() {

}
void Bullet::hurt() {
	this->HP--;
}
void collideRect(cocos2d::CCPoint point) {

}

