#define RES_LOADING "res/loading.png"
#define RES_MENUTITLE "res/menuTitle.png"
#define RES_DIR "res/"
// music
#define RES_BUTTON_CLICK_MP3 "res/Music/buttonEffet.mp3"

#define RES_MAIN_MENU_MP3 "res/Music/mainMainMusic.mp3"
#define RES_BG_MP3	"res/Music/bgMusic.mp3"

#define RES_EFFECT_BTN "res/Music/buttonEffect.mp3"
#define RES_EFFECT_EXPLODE "res/Music/explodeEffect.mp3"
#define RES_EFFECT_FIR "res/Music/fireEffect.mp3"
#define RES_EFFECT_SHIP_DEST "res/Music/shipDestroyEffect.mp3"

#define RES_MUSIC "res/Music/"

#define RES_TEXTUREOPAQUEPACK_PLIST "res/textureOpaquePack.plist"
#define RES_TEXTURETRANSPARENTPACK_PLIST "res/textureTransparentPack.plist"
#define RES_EXPLOSION_PLIST "res/explosion.plist"

#define RES_LEVEL1_TMX "res/level01.tmx"

#include "cocos2d.h"

using namespace cocos2d;

class GameConfig {
public:
	static bool getSound();
	static void setSound(bool sound);
	static void changeSound();
	static bool sound;

	static CCArray* ENEMIES;
	static CCArray* ENEMIES_BULLETS;
	static CCArray* PLAYER_BULLETS;
	static CCArray* HITS;

	static const int LIFEUP_SOURCE[];

	static void initArray();

};

