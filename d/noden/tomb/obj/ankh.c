#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "spider ankh", "蜘蛛聖標" );
	add( "id", ({ "ankh" }) );
   set_short( "蜘蛛聖標" );
	set_long(
		"這是一個小型的聖標，上面扎著一條破布，聖標中間一個圓形的\n"
		"突起上刻著一個蜘蛛的記號。\n"
	);
	set( "type", "misc" );
   set( "material", "wood" );
   set( "weight", 50 );
	set( "armor_class", 0 );
   set( "defense_bonus", 5 );
   set( "special_defense", ([ "poison":20, "acid" : -25 ]) );
   set( "value", ({ 980, "silver" }) );
   set( "extra_skills", ([ "depoison" : 10 ]) );
}
