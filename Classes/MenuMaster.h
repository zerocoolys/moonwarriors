/*
 * MenuMaster.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef MENUMASTER_H_
#define MENUMASTER_H_

#include "cocos2d.h"

using namespace cocos2d;
class MenuMaster {
public:
	static CCMenuItemFont* getMenuItemFont(const char* name);
	static CCMenuItemToggle* getMenuToggle(CCArray* array , CCObject* target , SEL_MenuHandler handler);
	static CCLabelTTF* getBackLabel();
	static void backToSysMenu();
private:
};

#endif /* MENUMASTER_H_ */
