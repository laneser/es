#include "saulin_monk.c"

void create()
{
	::create();
	set_level(14); 
	set_name( "yeng dou", "遠道" );
	add ("id", ({ "yeng", "dou","monk" }) );
	set_short( "遠道" );
	set_long(@C_LONG
遠道今年約二十六歲，他厭惡同族人以吸食別族的血為生的生存方式，所以 
不被同族人認同而遭追殺，一路逃至少林而獲收留。他喜歡練刀法，一套無 
色刀法練的非常熟練。 
C_LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "位" );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 16);
	set_perm_stat( "karma", 14);
	set_skill("longblade",80);
        set_skill("parry",70);
	set("special_defense", ([ "all":18, "none":15 ]) );
	set("max_fp", 800);
	set("force_effect", 2);
	set("force_points", 800);
	set("attack_skill",CLASS"wu_sur");
	set("gonfus/wu-sur",100);
	set("wealth/gold", 55);
	set_natural_weapon( 0, 7, 13 );
	set_natural_armor( 36, 34 );
    wield_weapon( SAULIN_OBJ"blade4" );
    equip_armor( SAULIN_OBJ"cloth5a" );
}
