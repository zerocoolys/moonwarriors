
// include
#define __INCLUDE__ #include "GameConfig.h" \
	#include "GameMaster.h" \
	#include "MusicMaster.h" \
	#include "ResourceManager.h"


// header method
#define INIT_METHOD static cocos2d::CCScene* scene(); \
	virtual bool init();


// Layer Scene method , to creat a Scene
#define SCENE_METHOD(_TYPE_) CCScene* _TYPE_::scene() { \
	CCScene * scene = NULL; \
	do { \
		scene = CCScene::create(); \
		CC_BREAK_IF(! scene); \
		_TYPE_ *layer = _TYPE_::create(); \
		CC_BREAK_IF(! layer); \
		scene->addChild(layer); \
	} while (0); \
	return scene; \
}

#define INIT_ARRAY(__NAME__) if(!__NAME__){ \
	__NAME__ = cocos2d::CCArray::create(); \
	}
