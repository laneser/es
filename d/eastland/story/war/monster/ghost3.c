#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(16);
	set_name( "special ghost", "魎鬼" );
	add( "id", ({ "ghost" }) );
	set_short( "魎鬼" );
	set_long(@LONG
魎鬼長的像個三歲娃娃，通身黑□透紅，長耳朵，紅眼睛，烏黑光□的長頭髮，喜
歡學人說話的聲音來迷惑人。魎鬼最怕的是一種龍的聲音，因為那種聲音迴環宛轉
，會使得它周身膽寒，如痴似醉，喪失戰鬥力。
LONG
	);
        set( "race","鬼");
	set( "unit", "個" );
	set( "alignment", -300 );
	set_natural_armor(50,25);
	set_natural_weapon(20,7,11);
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set( "aim_difficulty",
           ([ "critical":20, "vascular":20, "weakest":20 ]));
	set( "wealth/silver", 200 );
	set( "killer", 1 );
	set( "pursuing",1);
        set( "unbleeding",1);
        set( "moving",1);
        set( "speed",30);
        set( "war_points", 130 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry",60 );
	set_skill( "dodge", 60 );
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"scythe1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"魎鬼發出迷惑人的聲音！\n");
    (CONDITION_PREFIX + "confused")->apply_effect( victim, 5, 10 );          
    hurt_all("evil",45);
    return 1;    
}
