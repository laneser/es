#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet", "護身符" );
	add( "id", ({ "智者護身符" }) );
	set_short( "a wiser amulet", "智者護身符" );
	set_long(
		"This is Yamor's wiser amulet. You can see many symbols\n"
		"of fortune on it.\n",
		"這個護身符一向是亞默長老最常帶在身邊的，上面畫滿了各種\n"
		"代表平安、幸運的咒文。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
    set( "extra_status", ([ "int" : 1 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
