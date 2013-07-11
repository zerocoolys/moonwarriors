/*
 * GameLayer.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"
#include "LayerMacros.h"
#include "sprites/HitEffect.h"
#include "sprites/Enemy.h"

class GameLayer: public cocos2d::CCLayer {
public:
	CREATE_FUNC(GameLayer)
	;

	INIT_METHOD
	;
	static GameLayer* sharedGameLayer();

	void addBulletHits(HitEffect* hit, int zOrder);
	void addEnemy(Enemy* enemy, int z , int tag);
//	void addExplosions(Expl)
private:
	static GameLayer* instance;
	unsigned int _state;
};

#endif /* GAMELAYER_H_ */
