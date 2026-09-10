#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "merchant", "黑店商人" );
	set_short( "黑店商人" );
	set_long(@C_LONG
黑店商人平時最愛賭博。你可以問問他價格 ( price ) 看是否有什麼東西。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set( "no_attack", 1 );
        set_inventory( ({
            ({ "/d/eastland/beggar/item/nest", 10, 10 }),
            ({ "/d/eastland/beggar/item/bearpalm", 5, 5 })
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