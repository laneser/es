#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
	set_name( "black plaster", "黑玉斷續膏" );
	set_short( "黑玉斷續膏" );
	add("id",({"plaster"}));
	set_long(
		"這是刑老爹獨創的療傷聖品,不過藥材難尋。可以敷(apply)在傷口上。\n"
	);
	set( "unit", "盒" );
	set( "heal_apply", 9 );
	set( "duration", 30 );
	set( "weight", 10 );
	set( "value", ({ 50, "gold" }) );
}
