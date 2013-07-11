/*
 * HitEffect.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef HITEFFECT_H_
#define HITEFFECT_H_

#include "cocos2d.h"

class HitEffect: public cocos2d::CCSprite {
public:
	CREATE_FUNC(HitEffect)
	;
	void ctor();
	void destroy();

	HitEffect* getOrCreateHitEffect(cocos2d::CCPoint pos, float rotation,
			float scale);

	bool active;
private:
	void reset(cocos2d::CCPoint pos, float rotation, float scale);

};

#endif /* HITEFFECT_H_ */
