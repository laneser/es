#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("jade cloth","金縷玉衣");
    add("id",({"jade","cloth"}) );
    set_short( "金縷玉衣");
	set_long(
		"這是一件金縷玉衣，玉在東方人的心中可以避邪驅魔，帶來好運．\n"
		"這件衣服完全由玉製成，穿上它會有不可思議的效果．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 10 );
	set( "value", ({ 290, "gold" }) );
        set( "special_defense",(["evil":10,"poison":8,"devine":-10,"acid":6,"none":7]));
        set( "extra_stats",(["dex":-3,"kar":1,"str":-1]));
                                    
}
