#include "saulin_monk.c"

void create()
{
	::create();
	set_level(5);
	set_name( "kon gem", "老僧空見" );
	add ("id", ({ "kon", "gem","monk" }) );
	set_short( "老僧空見" );
	set_long( @LONG
空見大師年紀非常大了，身材極瘦而又枯乾，但雙目中卻泛出無比的慈祥
他精研金剛不壞體神功，向來是打不還手，罵不還口。昔日武林大寇黑風
掌謝震即是被他感化，投如佛門。
LONG
	);
    set( "alignment",2500);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "位" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set_skill("dodge",100);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("forgetful", 1);
          set("defense_skill",CLASS"body_def");    
          set("monk_gonfu/body-def",10);
	set("wealth/gold", 10);
	set_natural_weapon( 30, 15, 30 );
	set_natural_armor( 90, 65 );
        set("weight", 500);
}
