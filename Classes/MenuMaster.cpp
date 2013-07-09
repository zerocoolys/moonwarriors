/*
 * MenuMaster.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "MenuMaster.h"
#include "SysMenu.h"
using namespace cocos2d;

CCMenuItemFont* MenuMaster::getMenuItemFont(const char* name) {
	CCMenuItemFont::setFontName("Arial");
	CCMenuItemFont::setFontSize(18);
	CCMenuItemFont* menu = CCMenuItemFont::create(name);

	return menu;
}

CCMenuItemToggle* MenuMaster::getMenuToggle(CCArray* array, CCObject* target,
		SEL_MenuHandler handler) {
	CCMenuItemFont::setFontName("Arial");
	CCMenuItemFont::setFontSize(18);

	CCMenuItemToggle* soundToggle = CCMenuItemToggle::createWithTarget(target,
			handler, array);

	return soundToggle;
}

CCLabelTTF* MenuMaster::getBackLabel() {
	CCLabelTTF* label = CCLabelTTF::create("Go back", "Arial", 14);
	return label;
}

void MenuMaster::backToSysMenu() {
	CCScene* scene = CCScene::create();
	scene->addChild(SysMenu::create());
	CCDirector::sharedDirector()->replaceScene(
			CCTransitionFade::create(1.2, scene));
}
