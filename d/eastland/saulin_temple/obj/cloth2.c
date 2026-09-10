#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("gold pallium","紫羅架裟");
    add("id",({ "cloth", "pallium" }) );
    set_short("紫羅架裟");
	set_long(@C_LONG
這是一件用紫蠶絲所織成並滾上金邊的架裟，是當年東方帝國開國皇帝賜給
一十三位有功於帝國開國大業，又不願入朝為官的寺僧之禮。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
        set("material","monk");
	set( "armor_class", 35 );
	set( "defense_bonus", 5 );
	set( "value", ({ 190, "gold" }) );
}
