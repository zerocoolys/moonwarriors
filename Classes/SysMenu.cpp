/*
 * SysMenu.cpp
 *
 *  Created on: 2013-7-6
 *      Author: Administrator
 */

#include "SysMenu.h"
#include "GameMaster.h"
#include "GameConfig.h"
#include "SimpleAudioEngine.h"
#include "AboutLayer.h"

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

	CCSprite* pLoading = CCSprite::create(RES_LOADING);
	pLoading->setAnchorPoint(ccp(0,0));
//	pLoading->setPosition(ccp(0,0));

	this->addChild(pLoading, 0, 1);

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

	CCMenuItemSprite* gameSettings = CCMenuItemSprite::create(
			gameSettingsNormal, gameSettingsSelected, gameSettingsDisabled,
			this, menu_selector(SysMenu::onSettings));
	CCMenuItemSprite* about = CCMenuItemSprite::create(aboutNormal,
			aboutSelected, aboutDisabled, this,
			menu_selector(SysMenu::onAbout));

	CCMenu* mainMenu = CCMenu::create(newGame, gameSettings, about, NULL);
	mainMenu->alignItemsVerticallyWithPadding(10);
	this->addChild(mainMenu, 1, 2);
	mainMenu->setPosition(winSize.width / 2, winSize.height / 2);

	this->schedule(schedule_selector(SysMenu::update), 0.1);

	_ship = CCSprite::createWithSpriteFrameName("ship01.png");

	this->addChild(_ship, 0, 4);
	CCPoint pos = ccp(rand()* winSize.width, 0);
	_ship->setPosition(pos);
	_ship->runAction(
			CCMoveBy::create(2,
					ccp(rand()* winSize.width, pos.y + winSize.height + 100)));

	if (SOUND) {
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.7);
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
				"res/Music/mainMainMusic.mp3", true);
	}
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
				"res/Music/buttonEffet.mp3");
	}
}

void SysMenu::onNewGame() {
	//load resources
}

void SysMenu::onSettings() {
//	onButtonEffect();
//	CCScene* scene = CCScene::create();
//	scene.addChild(SettingsLayer.create());
//	cc.Director.getInstance().replaceScene(
//			cc.TransitionFade.create(1.2, scene));
}
void SysMenu::onAbout() {
	onButtonEffect();
	CCScene* scene = CCScene::create();
	scene->addChild(AboutLayer::create());
	CCDirector::sharedDirector()->replaceScene(
			CCTransitionFade::create(1.2, scene));
}
