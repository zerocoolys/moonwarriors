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

