#include <mudlib.h>

inherit ROOM;
inherit SELLER;

void create()
{       
        ::create();
        set_short("shop", "藥店");
        set_long( " no describe\n",
        "這是一間藥店！裡面烏燈黑火的看不見一個人！只隱約看見牆邊有一個人影。\n"
        "這裡有一樣行醫者必備的器具, 你可以參考掛在牆上的目錄(menu)。\n"
        );
        
        set("objects", ([
            "jack" : "/d/healer/building/monsters/jack"
        ]) );
        set( "light", 1 );
        set( "item_func", (["menu" : "show_menu"]) );
        set_inventory( ({
                ({"/d/healer/building/weapons/scalpel",5,5}),
        }) );
        reset();
}

void reset()
{
     room::reset();
     seller::reset();
     return;
}

int do_buy(string arg)
{
    if (this_player()->query("class") != "healer")
        return notify_fail("對不起，這裡只做醫生的生意，您請回吧!\n");
    return ::do_buy(arg);
}
