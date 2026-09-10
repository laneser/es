#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red pallium","大紅袈裟" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "大紅袈裟" );
	set_long(
		"這是一套羅漢高級弟子才有資格穿著的大紅袈裟。\n"
	);
	set( "unit", "領" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
