/*
 * GameLayer.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"
#include "LayerMacros.h"

class GameLayer: public cocos2d::CCLayer {
public:
	CREATE_FUNC(GameLayer)
	;

	INIT_METHOD
	;

private:
	unsigned int _state;
};

#endif /* GAMELAYER_H_ */
