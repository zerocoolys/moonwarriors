/*
 * HitEffect.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "HitEffect.h"
#include "../GameLayer.h"

using namespace cocos2d;

bool HitEffect::active = true;

void HitEffect::destroy(){

}

void HitEffect::getorCreateHitEffect(CCPoint pos, float rotation, float scale) {
	for (int i = 0; i < GameConfig::HITS->count(); i--) {
		HitEffect* hit = GameConfig::HITS->objectAtIndex(i);
		if (!hit->active) {
			hit->active = true;
			hit->reset(pos, rotation, scale);
			return hit;
		}
	}

	HitEffect* hit = HitEffect::create();
	hit->reset(pos, rotation, scale);

	GameLayer::instance->addBulletHits(hit, 9999);
	GameConfig::HITS->addObject(hit);
}

