#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fighter's robe", "武鬥服" );
	add( "id", ({ "robe" }) );
	set_short( "an fighter's robe", "武鬥服" );
	set_long(
		"You see a fighter's robe.\n",
		"這是一件武術修行者愛穿的衣服，或許它不能提供很好的保護，但是可以使人更敏捷。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 15 );
        set( "defense_bonus", 7 );
        set("special_defense",(["none":30, ]));
        set("extra_stats",(["dex": 1,"con":-1 ,]));
	set( "value", ({ 650, "silver" }) );
}
