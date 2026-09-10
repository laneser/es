#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "護身符" );
   set_short( "蜘蛛護身符" );
	set_long(
		"這個護身符是一個蜘蛛形狀的小包包，裡面裝滿了奇怪的藥粉或香料之類\n"
		"的東西，聞起來很刺鼻。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "poison":2, "fire":-2 ]) );
	set( "value", ({ 290, "silver" }) );
}
