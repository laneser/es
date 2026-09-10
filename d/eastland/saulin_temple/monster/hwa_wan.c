#include "saulin_monk.c"

void create()
{
	::create();
	set_level(10);
	set_name( "Hwa wan", "華妄" );
	add ("id", ({ "wan", "Hwa","monk" }) );
	set_short( "華妄" );
	set_long(@C_LONG
華妄原本是一個獵戶，生平殺生無數，一日行經少林，為其中唸經聲所震憾， 
頓時放下屠刀，削髮為僧。
C_LONG
	);
	set( "alignment",1200);
	set( "gender", "male" );
	set( "race", "orc" );
	set( "unit", "位" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 14 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 12);
	set_skill("unarmed",100);
	set_skill("dodge",55);
        set_skill("inner-force",100);
	set("special_defense", ([ "all":10, "none":10 ]) );
	set("max_fp", 300);
	set("force_effect", 2);
	set("force_points", 300);
	set("attack_skill",FIST"fu_hu");    
	set("wealth/gold", 25);
	set_natural_weapon( 10, 8, 18 );
	set_natural_armor( 35, 19 );
        set("weight", 700);
    equip_armor( SAULIN_OBJ"cloth7" );
}
