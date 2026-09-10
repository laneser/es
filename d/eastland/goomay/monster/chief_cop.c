
#include "../goomay.h"

inherit Army;
int key =0;
void create ()
{
        ::create();
        set_name( "Captain of Policeman", "段飛鷹" );
        add ("id",({ "captain","policeman","cop"}));
        set_short( "段飛鷹");
		set("level",13);
        set("unit","個");
        set_long(
@C_LONG
你看到一個高大強壯的人，他的年紀大約四十來歲，滿臉精幹警覺的神
色，他就是本鎮的捕頭－段飛鷹。他最大的興趣就是升官發財加拷打犯
人，他是一個認為只有重刑才能破案的人。
C_LONG
);
        set ("gender", "male");
        set ("race", "orc");
        set_natural_armor( 70, 25 );
        set_natural_weapon( 30, 15, 30 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_skill( "unarmed", 100 );
        set_skill( "parry", 100 );
        set("alt_corpse","NONE");
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
		"key"  : "@@ask_key",
                "jail" : "@@ask_key",
        ]) );

}

int ask_key()
{
        object me ;
        me=this_player();
   if( (int)me->query_quest_level("Goddess_statue") < 2 ){
	if (key)
	{
	tell_object(me,
        "段飛鷹道：「英雄閣下 !! 我已經把鑰匙給人了。」\n");
	return 1;
	}
	else
	{
        tell_object(me,
        "段飛鷹道：「原來是力戰妖怪的英雄 !! 鑰匙在這裡。」\n");
	key=1;
	new(Obj"key1")->move(this_object());
	command("give key to "+this_player()->query("name"));
        return 1;
	}
	}
        else
        {
        tell_object(me, 
"段飛鷹瞪著你道：「去 !! 去 !! 去 !! 沒事來問牢房鑰匙做什麼？你要劫獄嗎？」\n"
			);
                return 1;
}
}

void die()
{
 tell_room( environment(this_object()),
@C_DIE

段飛鷹突然對著你的背後大叫：「你們來的正好，把這個小子給我抓起來」
你回頭一看，發覺受騙了，等你再轉頭回來，段飛鷹已經跑的不見蹤影了。

C_DIE
 ,this_object() );

	::die(1);                
}

void reset()
{
	key=0;
}
