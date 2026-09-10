#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("bear fur cloth","熊皮烏油甲");
    add("id",({"fur","cloth"}) );
    set_short( "熊皮烏油甲");
	set_long(
		"這是用熊皮製成的戰甲，胸前有一塊巨大的月牙斑紋，其它地方黑\n"
		"油油的不帶一絲雜毛，你想這隻熊生前一定很可怕．\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "armor_class", 26 );
        set("material","leather");
	set( "defense_bonus", 4 );
	set( "value", ({ 175, "gold" }) );
}
