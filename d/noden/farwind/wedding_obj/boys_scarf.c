#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "絲質領巾");
        add( "id", ({ "scarf" }) );
   set_short("絲質領巾");
        set_long(
                "一條男士在正式場合結的領巾。\n"
        );
        set("unit","條");
        set( "type", "cloak" );
        set( "material","cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 55 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
        set( "value", ({ 1800, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "male") {
        printf(
                  "別開玩笑了, 你想當男人婆嗎?\n" );
        return 1;
        }
}
