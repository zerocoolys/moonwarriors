/*
 * SysMenu.h
 *
 *  Created on: 2013-7-6
 *      Author: Administrator
 */

#ifndef SYSMENU_H_
#define SYSMENU_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "AboutLayer.h"
#include "SettingsLayer.h"
#include "LayerMacros.h"
#include "MusicMaster.h"
#include "GameControlMenu.h"
#include "GameLayer.h"

class SysMenu: public cocos2d::CCLayer {
public:
	// construct and desconstruct method
	CREATE_FUNC(SysMenu)
	;

	virtual bool init();

	static cocos2d::CCScene* scene();
	void onButtonEffect();
	void update();
	void onSettings();
	void onAbout();
	void onNewGame();
	void loadFinished();

//	void menuCloseCallback(CCObject* pSender);
};

#endif /* SYSMENU_H_ */
