#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("emperor robe","龍袍");
        add("id",({"robe"}) );
        set_short("龍袍");
	set_long(
"這是東方皇帝的龍袍，上面繡有一隻金龍。\n");
	set( "unit", "件" );
	set( "weight", 135 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "no_sale", 1 );
	set( "prevent_insert", 1 );
	set( "value", ({ 1000, "gold" }) );
}
