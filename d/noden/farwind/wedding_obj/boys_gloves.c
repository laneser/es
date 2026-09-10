#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("silk wedding gloves", "白色手套");
        add( "id", ({"gloves" }) );
   set_short("白色手套");
        set_long(
                "一雙絲質白色手套，專為和禮服搭配而設計。\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set( "material" ,"cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 2880, "silver" }) );
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
