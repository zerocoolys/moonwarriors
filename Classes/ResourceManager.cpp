/*
 * ResourceManager.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "LayerMacros.h"

#include "ResourceManager.h"
#include "GameConfig.h"

using namespace cocos2d;

CCSprite* ResourceManager::getBackground() {
	CCSprite* sp = CCSprite::create(RES_LOADING);
	sp->setAnchorPoint(ccp(0,0));
	return sp;
}

CCSprite* ResourceManager::getBackground(const CCPoint& anchor) {
	CCSprite* sp = CCSprite::create(RES_LOADING);
	sp->setAnchorPoint(anchor);
	return sp;
}

CCNode* ResourceManager::getTitle(const char* resName,const CCRect rect ,const CCPoint point){
	CCTexture2D* cacheImage = CCTextureCache::sharedTextureCache()->addImage(resName);
	CCSprite* title = CCSprite::createWithTexture(cacheImage,rect);
	title->setPosition(point);
	return title;
}
