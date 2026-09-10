#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yellow pallium","黃色袈裟" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "黃色袈裟" );
	set_long(
		"這是一套只有戒律院高級弟子才有資格穿著的黃色袈裟。\n"
	);
	set( "unit", "領" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
