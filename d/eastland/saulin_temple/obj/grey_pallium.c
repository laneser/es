#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("grey pallium","灰補衲");
    add("id",({"cloth","pallium"}) );
    set_short( "灰補衲");
	set_long(
		"這是一件看來很陳舊的百衲袈裟，用灰布織就並經過高僧的祝福，是一件上好的袈裟。\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 9 );
	set( "value", ({ 800, "silver" }) );
}
