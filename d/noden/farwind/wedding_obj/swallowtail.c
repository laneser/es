#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("swallowtail","燕尾禮服");
        add("id",({"suit"}) );
   set_short( "新郎燕尾服");
        set_long(
"這是一件白色的燕尾服，純白的顏色代表純潔無暇的愛情。\n"
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set("material","cloth" ) ;
        set( "armor_class", 28 );
        set( "defense_bonus", 5 );
   set( "wedding_obj", 1 );
        set( "no_sale", 1 );
   set( "value", ({ 3180, "silver" }) );
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
