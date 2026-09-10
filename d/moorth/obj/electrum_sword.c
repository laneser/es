#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "electrum sword", "電光劍" );
	add( "id", ({ "short sword", "sword" }) );
   set_short( "電光劍" );
	set_long(
             "這是一把用默爾斯最新鑄劍術打造而成的短刃, 黑色的刀身中隱隱\n"
             "透出幾絲閃黃的光芒。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
   set( "weight", 72 );
   set( "second", 1 );
   set( "weapon_class", 35 );
   set( "min_damage", 19 );
   set( "max_damage", 30 );
   set( "value", ({ 999, "silver" }) );
}
