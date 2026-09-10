#include "mudlib.h"
inherit ARMOR;

void create()
{
    set_name( "long skirt", "白色新娘曳地長裙");
        add( "id", ({ "skirt" }) );
   set_short( "白色新娘曳地長裙");
        set_long(
                "這是一件由天然蠶絲織成的曳地白色新娘長裙。\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "armor_class", 8 );
        set("material","cloth");
        set( "defense_bonus", 2 );
        set( "weight", 70 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3250, "silver" }) );
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
