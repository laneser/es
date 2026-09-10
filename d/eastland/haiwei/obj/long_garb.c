#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long garb", "長袍馬褂" );
	add( "id", ({ "garb" }) );
	set_short( "長袍馬褂" );
	set_long("這是一件很普通的長袍馬褂。\n");
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 8 );
	set( "defense_bonus", 1 );
	set( "weight", 50 );
	set( "value", ({ 240, "silver" }) );
}
