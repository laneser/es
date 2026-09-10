#include "../../story.h"

inherit WMOB"warmob";

void create()
{
	::create();
	set_level(14);
	set_name( "special ghost", "魑鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魑鬼" );
	set_long(@LONG
一個類似人的臉和野獸身軀的影子，黑朦朦的令人看不清它究竟是什麼。它似乎對
著你張牙舞爪，不住發出嗡嗡的聲音。
LONG
	);
        set( "race", "鬼");
	set( "unit", "個" );
	set( "alignment", -300 );
	set_natural_armor(70,15);
        set( "special_defense", ([ "all":10 ]) );
        set( "aim_difficulty",
           ([ "critical":10, "vascular":10, "weakest":20 ]));
	set( "wealth/silver", 110 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 60 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set( "chat_chance", 5 );
	set( "att_chat_output", ({
		"魑鬼說道：別再做頑強的抵抗了，沒人擋得住蚩尤大軍的！\n"
	}) );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"魑鬼口吐陣陣黑色的氣體！!\n");
    hurt_all("evil",30);
    return 1;    
}
