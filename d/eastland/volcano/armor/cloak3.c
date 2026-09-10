#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "warrior's cloak", "武者鬥蓬" );
	add( "id", ({ "cloak" }) );
	set_short( "武者鬥蓬" );
	set_long( 
    @LONG
這是一件古代武者所穿著的鬥蓬，跟著主人南征北討，沾滿了敵人的血跡。
LONG
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 8 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([
	  "energy" : 10, "electric" : -5 ])
    );
	set( "weight", 50 );
	set( "value", ({ 1500, "silver" }) );
}
