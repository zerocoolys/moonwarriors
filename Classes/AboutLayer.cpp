/*
 * AboutLayer.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "AboutLayer.h"
#include "GameConfig.h"
#include "SysMenu.h"
#include "ccTypes.h"

using namespace cocos2d;

CCScene* AboutLayer::scene() {

	CCScene * scene = NULL;
	do {
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		AboutLayer *layer = AboutLayer::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool AboutLayer::init() {

	if (!CCLayer::init()) {
		return false;
	}

	CCSprite* sp = CCSprite::create(RES_LOADING);
	sp->setAnchorPoint(ccp(0,0));
	this->addChild(sp, 0, 1);

	CCTexture2D* cacheImage = CCTextureCache::sharedTextureCache()->addImage(
			RES_MENUTITLE);
	CCSprite* title = CCSprite::createWithTexture(cacheImage,
			CCRectMake(0,36,100,34));
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	title->setAnchorPoint(ccp(winSize.width / 2, winSize.height));
	this->addChild(title);

	CCLabelTTF* about =
			CCLabelTTF::create(
					"   This showcase utilizes many features from Cocos2d-html5 engine, including: Parallax background, tilemap, actions, ease, frame animation, schedule, Labels, keyboard Dispatcher, Scene Transition. \n    Art and audio is copyrighted by Enigmata Genus Revenge, you may not use any copyrigted material without permission. This showcase is licensed under GPL. \n \n Programmer: \n Shengxiang Chen \n Dingping Lv \n Effects animation: Hao Wu\n Quality Assurance:  Sean Lin",
					"Arial", 14, CCSizeMake(winSize.width * 0.85, 320),
					kCCTextAlignmentLeft);
	about->setPosition(ccp(winSize.width / 2, winSize.height / 2 - 20));
	about->setAnchorPoint(ccp(0.5, 0.5));
	this->addChild(about);

	CCLabelTTF* label = CCLabelTTF::create("Go back", "Arial", 14);
	CCMenuItemLabel* back = CCMenuItemLabel::create(label, this,
			menu_selector(AboutLayer::onBackButton));
	CCMenu* menu = CCMenu::create(back, NULL);
	menu->setPosition(winSize.width / 2, 40);
	this->addChild(menu);

	return true;
}

void AboutLayer::onBackButton() {
	CCScene* scene = CCScene::create();
	scene->addChild(SysMenu::create());
	CCDirector::sharedDirector()->replaceScene(
			CCTransitionFade::create(1.2, scene));
}
