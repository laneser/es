#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "katana", "寶刀" );
   set_short( "寶刀「菊一文字」" );
	set_long(
		"這是一把擦得雪亮的武士刀，它的刀刃只有一面，但是刀身的硬度要比\n"
		"一般常見的劍高得多，用來劈砍的時候所造成的傷害較大。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 90 );
	set( "weapon_class", 26 );
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "bleeding", 10 );
	set( "value", ({ 700, "silver" }) );
}
