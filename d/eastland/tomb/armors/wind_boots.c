#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind boots", "清風靴" );
	add( "id", ({ "boots" }) );
	set_short( "清風靴" );
	set_long( 
@C_TOPIC
這是風之護衛所穿的靴子，閃耀著淺紫色的光芒。
C_TOPIC
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 6 );
	set( "defense_bonus", 2 );
	set( "extra_skills", ([ "dodge" :15 ]) );
	set( "extra_stats", ([ "pie":-1 ]) );     
	set( "weight", 25 );
	set( "value", ({ 1600, "silver" }) );
}
