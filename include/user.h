 
//  File  :  /include/user.h
//
//  The specific user body inherits (Not used by MONSTER or GHOST)
// The #defines are in user2.h, so they may be included without
// inheriting all this code.

//	每次心跳從指令佇列消化幾個。這是節流閥：太小則連打的人要等很久，
//	太大則等於沒有節流（玩家可以瞬間爆發任意多動作）。
#define CMDS_PER_TICK 4

inherit "/std/user/tsh";
inherit "/std/user/autoload";
inherit "/std/user/save";
inherit "/std/user/explore"; 
inherit "/std/user/quest";
