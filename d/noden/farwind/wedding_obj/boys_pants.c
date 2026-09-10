#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "長褲");
        add( "id", ({ "pants" }) );
   set_short( "新郎禮服的長褲");
        set_long(
                "這是一件由天山蠶絲織成的長褲。\n"
        );
        set( "unit", "條");
        set( "type", "legs" );
        set( "material","cloth" ) ;
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 3620, "silver" }) );
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
