/*
 * SysMenu.cpp
 *
 *  Created on: 2013-7-6
 *      Author: Administrator
 */

#include "SysMenu.h"
#include "GameConfig.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
//for audio
using namespace CocosDenshion;

CCSprite* _ship;
CCSize winSize;

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

	winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* pLoading = CCSprite::create("res/loading.png");
	pLoading->setAnchorPoint(ccp(0,0));

	this->addChild(pLoading, 0);

	CCSprite* logo = CCSprite::create("res/logo.png");
	logo->setAnchorPoint(ccp(0,0));
	logo->setPosition(ccp(0,250));
	this->addChild(logo, 10, 1);

	CCSprite* newGameNormal = CCSprite::create("res/menu.png",
			CCRectMake(0,0,126,33));
	CCSprite* newGameSelected = CCSprite::create("res/menu.png",
			CCRectMake(0, 33, 126, 33));
	CCSprite* newGameDisable = CCSprite::create("res/menu.png",
			CCRectMake(0, 33 * 2, 126, 33));

	CCSprite* gameSettingsNormal = CCSprite::create("res/menu.png",
			CCRectMake(126,0,126,33));
	CCSprite* gameSettingsSelected = CCSprite::create("res/menu.png",
			CCRectMake(126, 33, 126, 33));
	CCSprite* gameSettingsDisabled = CCSprite::create("res/menu.png",
			CCRectMake(126, 33 * 2, 126, 33));

	CCSprite* aboutNormal = CCSprite::create("res/menu.png",
			CCRectMake(252,0,126,33));
	CCSprite* aboutSelected = CCSprite::create("res/menu.png",
			CCRectMake(252, 33, 126, 33));
	CCSprite* aboutDisabled = CCSprite::create("res/menu.png",
			CCRectMake(252, 33 * 2, 126, 33));

	CCMenuItemSprite* newGame = CCMenuItemSprite::create(newGameNormal,
			newGameSelected, newGameDisable, this,
			menu_selector(SysMenu::onButtonEffect));

	CCMenu* mainMenu = CCMenu::create(newGame);
	mainMenu->alignItemsVerticallyWithPadding(10);
	this->addChild(mainMenu, 1, 2);
	mainMenu->setPosition(winSize.width / 2, winSize.height / 2);

	this->schedule(schedule_selector(SysMenu::update),0.1);

    _ship = CCSprite::createWithSpriteFrameName("res/ship01.png");

	return true;
}
void SysMenu::update() {
	if (_ship->getPosition().y > 480) {
		CCPoint pos = ccp(rand() * winSize.width, 10);
		_ship->setPosition(pos);
		_ship->runAction(
				CCMoveBy::create(5 * rand(),
						ccp(rand() * winSize.width, pos.y + 480)));
	}
}

void SysMenu::onButtonEffect() {
	if (SOUND) {
		SimpleAudioEngine::sharedEngine()->playEffect(
				"/res/Music/buttonEffet.mp3");
	}
}
