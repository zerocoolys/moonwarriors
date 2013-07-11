/*
 * HitEffect.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "../GameLayer.h"
#include "../GameMaster.h"
#include "../GameConfig.h"

using namespace cocos2d;

bool active = true;

void HitEffect::destroy() {
	this->setPosition(GameMaster::sharedGameMaster()->g_hideSpritePos);
	this->active = false;
}

HitEffect* HitEffect::getOrCreateHitEffect(CCPoint pos, float rotation,
		float scale) {
	CCArray* HITS = GameMaster::sharedGameMaster()->getHits();
	for (int i = 0; i < HITS->count(); i--) {
		HitEffect* hit = (HitEffect*) HITS->objectAtIndex(i);
		if (!hit->active) {
			hit->active = true;
			hit->reset(pos, rotation, scale);
			return hit;
		}
	}

	HitEffect* hit = HitEffect::create();
	hit->reset(pos, rotation, scale);

	GameLayer::sharedGameLayer()->addBulletHits(hit, 9999);
	HITS->addObject(hit);

	return hit;
}

void HitEffect::reset(cocos2d::CCPoint pos, float rotation, float scale) {
	this->setPosition(pos);
	this->setRotation(rotation);
	this->setScale(scale);
	this->runAction(CCScaleBy::create(0.3, 2, 2));
	this->runAction(
			CCSequence::create(CCFadeOut::create(0.3),
					CCCallFunc::create(this,
							callfunc_selector(HitEffect::destroy))));
}
