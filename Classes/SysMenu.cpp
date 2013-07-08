/*
 * SysMenu.cpp
 *
 *  Created on: 2013-7-6
 *      Author: Administrator
 */

#include "SysMenu.h"

using namespace cocos2d;

CCScene* SysMenu::scene() {

	CCScene * scene = NULL;
	do {
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SysMenu *layer = SysMenu::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool SysMenu::init() {
	if (!CCLayer::init()) {
		return false;
	}

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
			"res/textureTransparentPack.plist");

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* pLoading = CCSprite::create("res/loading.png");
	pLoading->setAnchorPoint(ccp(0,0));

	this->addChild(pLoading, 0);

	return true;
}
