/*
 * SettingsLayer.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef SETTINGSLAYER_H_
#define SETTINGSLAYER_H_

#include "cocos2d.h"
#include "LayerMacros.h"

class SettingsLayer: public cocos2d::CCLayer {
public:
	INIT_METHOD;

	CREATE_FUNC(SettingsLayer)
	;

	void onSoundControl();
	void onModeControl();
	void onBackButton();
};

#endif /* SETTINGSLAYER_H_ */
