#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "尖頭皮鞋");
        add( "id", ({ "boots" }) );
   set_short("尖頭皮鞋");
        set_long(
                "一雙黑的發亮的尖頭皮鞋。\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material" , "leather" ) ; 
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
        set( "weight", 100 );
   set( "value", ({ 3000, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
   if ( (string)this_player()->query("gender") != "male") {printf(
         "別開玩笑了, 你想當男人婆嗎?\n" );
   return 1;
   }
}
