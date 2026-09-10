#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dragon gloves", "龍紋手套" );
	add( "id", ({ "dragon", "gloves", }) );
	set_short( "dragon gloves", "龍紋手套" );
	set_long(@C_TOPIC
一雙華麗的手套，上面繡著一隻活靈活現的飛龍，使得這個手套生色不少。
C_TOPIC
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "cloth");
        set( "armor_class", 4 );
	set( "defense_bonus", 5 );
	set( "special_defense",
	    ([ "acid":10, "poison":5 ]) );    
	set( "weight", 10 );
	set( "value", ({ 2500, "silver" }) );
}
