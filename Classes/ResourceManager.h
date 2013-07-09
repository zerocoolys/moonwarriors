/*
 * ResourceManager.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "cocos2d.h"

using namespace cocos2d;

class ResourceManager {
public:
	static CCSprite* getBackground();
	static CCSprite* getBackground(const CCPoint& point);
	static CCNode* getTitle(const char* resName, const CCRect rect, const CCPoint point);
};

#endif /* RESOURCEMANAGER_H_ */
