#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "白色新娘頭紗");
        add( "id", ({ "lace" }) );
   set_short( "白色新娘頭紗");
        set_long(
		 "這是用純白的蕾絲做成的美麗頭紗，上面還綴著幾朵紅色的玫瑰。\n"
        );
        set("unit","頂");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
   set( "wedding_obj", 1 );
	set( "no_sale",1);
   set( "value", ({ 2800, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "female") {
        printf(
                  "別開玩笑了, 你想當人妖嗎?\n" );
        return 1;
        }
}

