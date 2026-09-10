#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(18);
	set_name( "wind god", "風伯" );
	add( "id", ({ "god","wind" }) );
	set_short( "風伯" );
	set_long(@LONG
風伯長得矮小肥胖不堪，全身一色白衣穿著，背著一個大袋子，走起路來一擺擺的
，在他周圍好似會生風。風伯是蚩尤大軍裡用來對付應龍的，平常人是禁不起他那
一吹。  
LONG
	);
	set( "unit", "個" );
	set( "alignment", -300 );
	set( "weight",1500);
	set( "gender","male");
	set_natural_armor(50,20);
	set_natural_weapon(17,16,18);
        set( "special_defense", ([ "all":40,"none":30 ]) );
        set( "aim_difficulty",
           ([ "critical":40, "vascular":40, "weakest":40 ]));
	set( "wealth/silver", 800 );
	set( "killer", 1 );
	set( "pursuing",1);
        set( "moving",1);
        set( "speed",30);
        set( "war_points", 400 );
	set( "max_hp",700);
        set( "hit_points",700);
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 28 );
	set_skill( "wand", 100 );
        set_skill( "parry", 90 );
	set_skill( "dodge", 90 );
        set("wimpy",100);
        set("tactic_func","my_tactic");
        wield_weapon(WWEA"staff1");
        equip_armor(WARM"cloth2");
        equip_armor(WARM"gloves1");
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(7) > 1 ) return 0;
    tell_room(environment(),"\n從風伯後面的袋子裡吹出一陣大風～～\n\n");
    hurt_all("evil",70);
    return 1;    
}
