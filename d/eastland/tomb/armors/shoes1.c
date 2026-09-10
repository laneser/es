#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "holy shoes", "滅魔鞋" );
	add( "id", ({ "shoes", }) );
	set_short( "滅魔鞋" );
	set_long( @C_TOPIC
一雙不起眼的鞋子，卻好像隱含著什麼力量。
C_TOPIC
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 6 );
	set( "defense_bonus", 3 );
	set( "special_defense", 
	     ([ "evil": 5 ]) );
	set( "weight", 30 );
	set( "value", ({ 1000, "silver" }) );
}
