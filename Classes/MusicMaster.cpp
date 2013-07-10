/*
 * MusicMaster.cpp
 *
 *  Created on: 2013-7-9
 *      Author: Administrator
 */

#include "MusicMaster.h"
#include "SimpleAudioEngine.h"
#include "GameConfig.h"

using namespace CocosDenshion;

void MusicMaster::playBackgroundMusicLoop(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(fileName, true);
	}
}
void MusicMaster::playBackgroundMusicOneTime(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(fileName, false);
	}
}

void MusicMaster::stopBackgroundMusic() {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void MusicMaster::playEffectLoop(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playEffect(fileName, true);
	}
}
void MusicMaster::playEffectOneTime(const char* fileName) {
	if (GameConfig::sound) {
		SimpleAudioEngine::sharedEngine()->playEffect(fileName, false);
	}
}

