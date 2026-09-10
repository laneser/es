#include "../moyada.h"
inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(5);
	set_name( "green slime", "綠色史萊姆" );
	add ("id", ({ "slime", }) );
	set_short( "綠色史萊姆" );
	set_long( @LONG
綠色的軟體怪，身體黏黏答答的，怪噁心的。
LONG
	);
   set( "race", "undead" );
	set( "alignment", -100 );
    set( "unit", "只" );
	set_perm_stat( "dex", 3 );
	set_perm_stat( "str", 2 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 3 );
	set_perm_stat( "piety", 2 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 140);
	set ("hit_points", 140);
	set_natural_weapon( 13, 6, 9 );
	set_natural_armor( 100, 9 );
	set ("time_to_heal", 6);
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("special_defense",
	    ([ "all" : 30, "cold" : -50, ]) );
    set ("weight", 100);
    set ("exp_reward", 370);
    set ("chat_chance",5);
    set ("chat_output", ({
      "綠色史萊姆蠕動一下，爬過食物殘渣並向你移動過來。\n"
    }) );
    set_c_verbs( ({ "%s蠕動到%s身上", "%s撲到%s臉上" }) );
    set_c_limbs( ({ "身體"  }) );
    set( "c_death_msg", "%s停止蠕動，死了.....\n" );
}
