#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "桂老爹" );
   add( "id", ({ "guey", "father" }) );
   set_short( "桂老爹" );
	set_long(
        "你看到一個狀似痴呆, 面黃肌瘦的老頭, 正獨自怔怔地望著天空。\n"
        "而且你不時聽到一種幽幽淡淡, 若有似無的嘆息聲。\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
   set( "alt_corpse", IANMOB"zombie1" );
	set( "inquiry", ([
       "sheaumei" : "@@ask_name"
	]) );
}


void ask_name(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
              "桂老爹怒吼道: 又出現另一個淫賊! 待會再收拾你!\n",
			this_object() );
	} else {
            tell_room( environment(),
                 "桂老爹怒吼道: 為甚你要打聽我女兒的名子? 啊! 你一定是淫賊! 下地獄吧!\n",
			this_object() );
		kill_ob( player );
	}
}

void die()
{
        tell_room( environment(this_object()), 
          "\n桂老爹身受重傷, 不支倒地........\n\n"
          "就在你想離去時............\n\n"
          "突然桂老爹又站了起來, 繼續攻擊你! 原來這老爹是□變啊!!\n\n"
          , this_object() );
        ::die(1);
}
