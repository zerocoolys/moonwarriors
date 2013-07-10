/*
 * Enemy.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "Enemy.h"
#include "../config/EnemyType.h"

using namespace cocos2d;

void Enemy::setZZOrder(unsigned int var) {
	Enemy::zOrder = var;
}

unsigned int Enemy::getZZOrder() {
	return Enemy::zOrder;
}

void Enemy::ctor(EnemyType* enemy) {
	this->init();
	this->HP = enemy->getHP();
	this->moveType = enemy->getMoveType();
	this->scoreValue = enemy->getScoreValue();

	this->enemyType = enemy->getType();

	this->initWithFile(enemy->getTextureName());
	this->schedule(schedule_selector(Enemy::shoot), this->getDelayTime());

}

void Enemy::shoot(){
	CCPoint ccp = this->getPosition();

}

void Enemy::destroy(){

}

