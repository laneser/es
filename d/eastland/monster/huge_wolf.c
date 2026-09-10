// /u/m/mad/special/wolf.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(8);
   set_name( "huge hyaena", "巨土狼" );
   add( "id", ({ "wolf" }) );
   set_short("巨土狼");
	set_long(
           "你看到一隻兇惡的土狼，對著你發出「嗚嗚」的低吼。\n"
	);
   set( "race", "beast" );
   set( "unit", "只" );
   set_perm_stat( "str", 10 );
   set_skill( "dodge", 50 );
   set_natural_weapon( 20, 8, 20 );
   set_c_verbs( ({ "%s用前爪撲向%s", "%s張開滿口利齒的嘴，往%s咬去" }) );
   set_c_limbs( ({ "頭部", "身體", "尾巴", "腿部" }) );
}

void die()
{
   object killer;

   killer=query("last_attacker");
   killer->set_temp("killed_wolf",1);
   ::die();
}
