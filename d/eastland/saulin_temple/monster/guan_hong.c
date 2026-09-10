#include "saulin_monk.c"

void create()
{
	::create();
	set_level(12); 
	set_name( "guan hong", "觀宏" );
	add ("id", ({ "guan", "hong","monk" }) );
	set_short( "觀宏" );
	set_long(@C_LONG
觀宏今年二十歲，他不喜歡像一般的魔族一樣四處侵略，所以投身少林 
他練就一手好棍法，行俠仗義，四處助人。 
C_LONG
	);
    set( "alignment",1200);
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "位" );
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 14 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 12 );
	set_perm_stat( "piety", 14);
	set_perm_stat( "karma", 14);
	set_skill("bo",75);
	set_skill("dodge",10);
        set_skill("parry",60);
	set("special_defense", ([ "all":15, "none":10 ]) );
	set("max_fp", 600);
	set("force_effect", 2);
	set("force_points", 600);
          set("attack_skill",CLASS"fu_mo");    
          set("defense_type","parry");    
          set("gonfus/fu-mo",100);
	set("wealth/gold", 36);
	set_natural_weapon( 8, 3, 10 );
	set_natural_armor( 36, 18 );
        set("weight", 500);
    wield_weapon( SAULIN_OBJ"copper_club" );
    equip_armor( SAULIN_OBJ"cloth5a.c" );
}
