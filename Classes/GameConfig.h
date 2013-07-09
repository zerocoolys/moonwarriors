#define RES_LOADING "res/loading.png"
#define RES_MENUTITLE "res/menuTitle.png"

// music
#define RES_BUTTON_CLICK_MP3 "res/Music/buttonEffet.mp3"
#define RES_MAIN_MENU_MP3 "res/Music/mainMainMusic.mp3"

class GameConfig {
public:
	static bool getSound();
	static void setSound(bool sound);
	static void changeSound();
	static bool sound;
};
