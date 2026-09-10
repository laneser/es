#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "白色新娘頭紗");
        add( "id", ({ "lace" }) );
        set_short( "a wedding lace", "白色新娘頭紗");
        set_long(
                "A white wedding lace .\n",
		 "這是用純白的蕾絲做成的美麗頭紗，上面還綴著幾朵紅色的玫瑰。\n"
        );
        set("unit","頂");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
	set( "no_sale",1);
        set( "value", ({ 1800, "silver" }) );
}



