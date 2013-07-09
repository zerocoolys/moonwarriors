/*
 * SettingsLayer.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "SettingsLayer.h"
#include "GameMaster.h"
#include "GameConfig.h"

#include "ResourceManager.h"
#include "MusicMaster.h"
#include "MenuMaster.h"
#include "SysMenu.h"

using namespace cocos2d;

bool SettingsLayer::init() {
	if (!CCLayer::init()) {
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	this->addChild(ResourceManager::getBackground());

	this->addChild(
			ResourceManager::getTitle(RES_MENUTITLE, CCRectMake(0,0,134,34),
					ccp(winSize.width/ 2 , winSize.height - 120)));

	CCMenuItemFont* soundMenu = MenuMaster::getMenuItemFont("Sound");
	soundMenu->setEnabled(false);

//	CCMenuItemFont::setFontName("Arial");
//	CCMenuItemFont::setFontSize(18);
//	CCMenuItemToggle* soundToggle = CCMenuItemToggle::createWithTarget(this,
//			menu_selector(SettingsLayer::onSoundControl),
//			CCMenuItemFont::create("On"), CCMenuItemFont::create("Off"));
	CCArray* soundArray = CCArray::create(CCMenuItemFont::create("On"),
			CCMenuItemFont::create("Off"), NULL);
	CCMenuItemToggle* soundToggle = MenuMaster::getMenuToggle(soundArray, this,
			menu_selector(SettingsLayer::onSoundControl));
	soundToggle->setSelectedIndex((GameConfig::sound) ? 0 : 1);

	CCMenuItemFont* modeMenu = MenuMaster::getMenuItemFont("Mode");
	modeMenu->setEnabled(false);

	CCArray* modeArray = CCArray::create(CCMenuItemFont::create("Easy"),
			CCMenuItemFont::create("Normal"), CCMenuItemFont::create("Hard"),
			NULL);
	CCMenuItemToggle* modeToggle = MenuMaster::getMenuToggle(modeArray, this,
			menu_selector(SettingsLayer::onModeControl));

	CCLabelTTF* backLabel = MenuMaster::getBackLabel();
	CCMenuItem* backItem = CCMenuItemLabel::create(backLabel);
	backItem->setTarget(this, menu_selector(SettingsLayer::onBackButton));
	backItem->setScale(0.8);

	CCMenu* menu = CCMenu::create(soundMenu, soundToggle, modeMenu, modeToggle,
			backItem, NULL);
	menu->alignItemsInColumns(2, 2, 1);
	this->addChild(menu);

	CCPoint point = backItem->getPosition();
	point.y -= 50.0;
	backItem->setPosition(point);

	return true;
}

void SettingsLayer::onSoundControl() {
	GameConfig::changeSound();

	if (GameConfig::sound) {
		MusicMaster::playBackgroundMusicLoop(RES_MAIN_MENU_MP3);
	} else {
		MusicMaster::stopBackgroundMusic();
	}
}

void SettingsLayer::onModeControl() {

}

void SettingsLayer::onBackButton() {
	MenuMaster::backToSysMenu();
}
SCENE_METHOD(SettingsLayer);
