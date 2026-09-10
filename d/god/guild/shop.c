#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
        ::create();
        set_short("A empty room", "魔神商店");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
你現在來到了魔神公會內部所附設的商店，這裡賣的東西雖然不是頂好，不
過對於剛來到這個世界的魔神而言，一些基本裝備總是有所幫助的，你可以翻閱
桌上的價目表(menu)，看看這裡賣些什麼。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits",([
    "north" : "/u/b/boss/god/guild/god_guild.c",
    "up"  : "/u/b/boss/workroom.c",  
        ]) );
        set( "item_func", ([ 
                "menu" : "show_menu" ]) );
        set_inventory( ({
              ({ "/d/eastland/saulin_temple/obj/seed", 10,10 }),
                ({ "/d/eastland/liang_shan/obj/snow_lily", 10, 10 }),
        }) );
        reset();
}

void reset()
{
        room::reset();
        seller::reset();
}
