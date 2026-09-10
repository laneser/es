#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Steel Pot", "不沾鍋" );
	add( "id", ({ "pot" }) );
	set_short( "a pot", "不沾鍋" );
	set_long(
		"??\n",
		"這面鍋是用某種你從沒見過的奇特金屬製成的\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 150 );
	set( "value", ({ 500, "silver" }) );
}
