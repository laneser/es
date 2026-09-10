#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("damo plate","破魔聖甲");
    add("id",({"plate","damo"}) );
    set_short( "damo plate","破魔聖甲");
	set_long(
"This is a suit of plate, and it is worn by damo.\n",
"這是一件看來很破舊的戰甲, 相傳是當年帝釋天和阿修羅戰鬥時所留下來的, 它隱隱\n"
"包圍著一陣光暈, 散發出一股神聖的氣息... \n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 360 );
	set( "type", "body" );
    set( "material","heavy_metal");
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "value", ({ 200, "gold" }) );
}
