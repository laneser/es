#include "/d/eastland/liang_shan/takeda.h"
#include <move.h>

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("草坪");
        set_long(@Clong
由鐵柵跨入，觸入眼簾的是一片修茸整齊的草坪，像是一張翠綠的地毯，上面
鋪著一塊塊石板作為小徑，非常典雅。草坪背後，忠義堂的紅柱金瓦高高的聳立著
，草坪一角另有一座水池。
Clong
        );
        set ("c_item_desc",([
                "pool":@pool
一個小小的池子，裡面生長了許多水生植物。
pool
                        ]));
        set_outside("eastland");
        set("have_iron",1);
        set("exits",([
                "north":TROOM"hall",
                "south":TROOM"gate2",
                        ]) );
        create_door("south","north",([
                "keyword" : ({"iron prism","prism" }),
                "status" : "closed",
                "c_desc" : "一道厚重的鐵柵",
                "c_name" : "鐵柵",
                "name":"iron prism",
                "desc":"an iron prism"
                        ]) );
        reset();
}

void init()
{
        add_action("do_search","search");
        add_action("do_take","take");
}

int do_search(string arg)
{
        if ( !arg || arg != "pool") return 0;
        if ( !query("have_iron") )
        {
                write("你期望在這個水池找到什麼，美女圖嗎??\n");
                return 1;
        }
        write("你開始搜尋這個水池，你注意到水池中的草堆裡有一個熨斗(iron)，"+
                        "也許你可以\n把它拿(take)起來\n");
        return 1;
}

int do_take(string arg)
{
        object iron;
          iron= new("/d/noden/hawk/obj/iron");
        if ( !arg || arg != "iron") return 0;
	if (!query("have_iron") ) return 0;
        write ("你把那熨斗從草堆中拿了出來...\n");
        if( (int)iron->move(this_player()) != MOVE_OK )
                iron->move( this_object() );
        this_player()->set_temp("help_tailor",1);
        delete("have_iron");
        return 1;
}

int clean_up() { return 0; }
