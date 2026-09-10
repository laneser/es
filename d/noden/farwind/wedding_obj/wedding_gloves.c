#include "mudlib.h"
inherit ARMOR;

void create()
{
   set_name("silk gloves", "白色純絲新娘手套");
        add( "id", ({"gloves" }) );
   set_short("白色純絲新娘手套");
        set_long(
                "一雙天然純絲織成的白色新娘手套。\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set("material","cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 2850, "silver" }) );
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
