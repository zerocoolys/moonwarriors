/*
 * GameType.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef GAMETYPE_H_
#define GAMETYPE_H_

typedef enum ENEMY_ATTACK_MODE {
	NORMAL = 0, TSUIHIKIDAN = 1
} EnemyAttackMode;

typedef enum ENEMY_MOVE_TYPE {
	ATTACK = 0, VERTICAL = 1, HORIZONTAL = 2, OVERLAP = 3
} EnemyMoveType;

typedef enum BULLET_TYPE {
	btPLAYER = 1, btENEMY = 2
} BulletType;

typedef enum WEAPON_TYPE {
	wONE = 1
} WeaponType;

typedef enum LEVEL {
	lSTAGE1 = 1, lSTAGE2 = 2, lSTAGE3 = 3
} Level;

typedef enum GAME_STATE {
	gsHOME = 0, gsPLAY = 1, gsOVER = 2
} GameState;

typedef enum UNIT_TAG {
	utENMEY_BULLET = 900, utPLAYER_BULLET = 901, utENEMY = 1000, utPLAYER = 1001
} UnitTag;

#endif /* GAMETYPE_H_ */
