/*
 * MusicMaster.h
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#ifndef MUSICMASTER_H_
#define MUSICMASTER_H_

class MusicMaster {
public:
	static void playBackgroundMusicLoop(const char* fileName);
	static void playBackgroundMusicOneTime(const char* fileName);
	static void stopBackgroundMusic();
	static void playEffectLoop(const char* fileName);
	static void playEffectOneTime(const char* fileName);
};

#endif /* MUSICMASTER_H_ */
