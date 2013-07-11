/*
 * GameLayer.cpp
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#include "GameLayer.h"
#include "LayerMacros.h"
#include "GameConfig.h"

using namespace cocos2d;

CCSpriteBatchNode* _texOpaqueBatch;
CCSpriteBatchNode* _texTransparentBatch;

SCENE_METHOD(GameLayer);

bool GameLayer::init() {

	if (!CCLayer::init()) {
		return false;
	}

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
			RES_TEXTUREOPAQUEPACK_PLIST);

	GameLayer::_state = 0;

	CCTexture2D* texOpaque = CCTextureCache::sharedTextureCache()->addImage(
			RES_TEXTUREOPAQUEPACK_PLIST);
	_texOpaqueBatch = CCSpriteBatchNode::createWithTexture(texOpaque);
	ccBlendFunc blendFunc = { GL_SRC_ALPHA, GL_ONE };
	_texOpaqueBatch->setBlendFunc(blendFunc);
	this->addChild(_texOpaqueBatch);

	CCTexture2D* texTransparent =
			CCTextureCache::sharedTextureCache()->addETCImage(
					RES_TEXTURETRANSPARENTPACK_PLIST);

	_texTransparentBatch = CCSpriteBatchNode::createWithTexture(texTransparent);
	this->addChild(_texTransparentBatch);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
}

GameLayer* GameLayer::instance = NULL;

GameLayer* GameLayer::sharedGameLayer() {
	if (GameLayer::instance == NULL) {
		GameLayer::instance = new GameLayer();
		GameLayer::instance->init();
	}
	return GameLayer::instance;
}

void GameLayer::addBulletHits(HitEffect* hit, int zOrder) {
	_texOpaqueBatch->addChild(hit, zOrder);
}

void GameLayer::addEnemy(Enemy* enemy, int z, int tag) {
	_texTransparentBatch->addChild(enemy, z, tag);
}
