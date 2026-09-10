#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron plate","裹金生鐵甲");
    add("id",({"plate","mail"}) );
    set_short( "iron plate","裹金生鐵甲");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"這是一件看來舊舊的金邊鐵甲冑，雖然年代久遠但保存完好，\n"
		"穿上它仍然可以上場作戰．\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 166, "gold" }) );
}
