/*
 * AboutLayer.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef ABOUTLAYER_H_
#define ABOUTLAYER_H_

#include "cocos2d.h"

class AboutLayer: public cocos2d::CCLayer {
public:
	CREATE_FUNC(AboutLayer)
	;

	static cocos2d::CCScene* scene();
	virtual bool init();
	void onBackButton();

};

#endif /* ABOUTLAYER_H_ */
