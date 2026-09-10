#include <../zeus.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "drunk", "老酒鬼 洪武" );
	set_short( "老酒鬼 洪武" );
	set_long(@AA
老酒鬼是一個非常神秘的人，沒有人知道他到底從何處而來，整天酒不離口，紅紅
的酒糟鼻成了他的招牌記號，有人在以前曾經經在他的雙臂上看見雙龍，因而推測
他可能是少林寺的俗家弟子．現在他又跑到酒境偷喝酒了．
AA
	);
    set( "alignment",-500);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "kar", 16 );
	set_skill("unarmed",90);
	set_skill("dodge",70);
	set("special_defense", ([ "all":20, "none":10 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":12, ]) );
	set("max_hp", 400);
	set("max_fp", 600);
	set("hit_points", 400);
	set("force_effect", 2);
	set("force_points", 600);
        set("attack_skill","monk/fist/drunk_fist");
        set("gonfus/drunk-fist",100);    
	set("wealth/gold", 50);
	set_natural_weapon(45,20,40);
	set_natural_armor( 66, 19 );
        set("weight", 700);
        set("inquiry",([
             "ghost":"@@ask_ghost"
             ]));
    equip_armor( ZOBJ"/boots" );
    equip_armor( ZOBJ"/red_coat" );
}
int ask_ghost()
{    tell_object(this_player(),
@ASK
我倒沒有見過鬼，我只知道段老大的弟弟常常在那邊出入！
ASK
);
     this_player()->set_temp("ask_ghost",1);
     }