#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(16);
	set_name( "large ghost", "神嵬" );
	add( "id", ({ "ghost" }) );
	set_short( "神嵬" );
	set_long(@LONG
神嵬長得人的臉，野獸的身子，卻只有一隻手一隻腳。
LONG
	);
	set( "unit", "個" );
        set( "race","鬼");
	set( "alignment", -300 );
	set_natural_armor(50,25);
	set_natural_weapon(40,18,30);
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set( "aim_difficulty",
           ([ "critical":20, "vascular":20, "weakest":20 ]));
	set( "wealth/silver", 200 );
	set( "killer", 1 );
        set( "unbleeding",1);
        set( "war_points", 150 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 20 );
	set_skill( "unarmed", 100 );
	set_skill( "unarm-parry",75 );
	set_skill( "dodge", 75 );
        set("tactic_func","my_tactic");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(5) > 1 ) return 0;
    tell_room(environment(),"從神嵬的身上噴出綠色的液體！\n");
    hurt_all("poison",60);
    return 1;    
}
