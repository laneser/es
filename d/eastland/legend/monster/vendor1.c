#include <mudlib.h>

inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "travel merchant", "旅行商人" );
    add( "id",({"merchant"}) );
    set_short( "旅行商人" );
    set_long(@LONG
一個從東方大陸來的商人，正在空地上休息。他平時喜歡到處旅行，結交一些英雄
好漢，順便做做生意。他賣的東西都是不二價，東西也不偷工減料，所以，很多人
都會來跟他買東西，你可以問問他價錢 ( price ) 看是否有什麼需要的。
LONG
    );
    set( "race", "human" );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
          ({ "/obj/bandage",10,10 }),
          ({ "/d/eastland/easta/obj/spicy_plaster", 10, 20 }),
          ({ "/d/eastland/easta/obj/green_pill", 10, 20 }),
    }) );
    set( "inquiry", ([
             "price" : "@@show_menu"
    ]) );
}
void init()
{
    npc::init();
    seller::init();
}