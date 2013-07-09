/*
 * AboutLayer.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef ABOUTLAYER_H_
#define ABOUTLAYER_H_

#include "cocos2d.h"
#include "LayerMacros.h"
class AboutLayer: public cocos2d::CCLayer {
public:
	CREATE_FUNC(AboutLayer)
	;

	INIT_METHOD
	;
	void onBackButton();
};

#endif /* ABOUTLAYER_H_ */
