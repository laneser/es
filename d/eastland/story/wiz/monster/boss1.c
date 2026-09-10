#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "hotal boss", "旅館老闆" );
	add( "id", ({ "boss" }) );
	set_short( "旅館老闆" );
	set_long(@C_LONG
一位□著啤酒肚的中年人，他正笑嘻嘻地站在櫃檯旁招呼客人。
C_LONG
        );
	set( "gender", "male" );
        set( "no_attack",1);
        set( "inquiry", ([
            "golden_older":"@@ask_older",
                  "killer":"@@ask_killer"
        ]) );
}
void ask_older(object asker)
{
tell_room(environment(),@LONG

老闆說道：老人？莫非你問的是居住在城外的那個脾氣古怪的老人家？
　　　　　如果你想去見他，最好帶特別的東西(special_things)去投
          他歡心，因為他生平最愛收集奇物異寶了。
　　
LONG
   );
}

void ask_killer(object asker)
{
write(@LONG
老闆說道：刺客？你說的是那天的刺客？我什麼都不知道喔，那天我只
　　　　　看到一個黑影(shadow)翻牆而過。

LONG
   );
}