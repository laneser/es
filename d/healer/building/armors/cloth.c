#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Doctor cloth","醫師診袍");
        add("id",({"cloth"}) );
        set_short("醫師診袍");
	set_long("這是行醫者最喜歡穿的衣服, 除了能夠保暖之外, 它\n"
	         "也是行醫者身份的象徵。\n");
	set( "unit", "件" );
	set( "weight", 80 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 17 );
	set( "defense_bonus", 5 );
	set( "value", ({ 1800, "silver" }) );
	set("no_sale",1);
}
