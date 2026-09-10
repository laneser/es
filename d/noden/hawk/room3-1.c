#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("市政大廳二樓");
        set("light",1);
        set_long( @LONG_DESCRIPTION
這裡是天空之城行政中心，裝璜的富麗堂皇，可表現出鳥人族高人一等的建
築技術，牆上掛滿了歷代鳥人族領袖的肖像(photos)。往北可以通到長老的辦公
室，往南，則是鳥人族領袖辦公的地方。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "north" : HAWK"room3-2",
                "west" : HAWK"room3-3",
                "down" : HAWK"room2-14",
                "south" : HAWK"room3-6",
                "east" : HAWK"room3-7",
                        ]) );
        set( "objects",([
                "prayer" : MOB"god2",
                        ]) );
        create_door("west","east",([
                "keyword":({"black door","door"}),
                "status":"closed",
                "c_desc":"一個黑色的門",
                "c_name":"黑玉門",
                "name":"black jade door",
                "desc":"a black jade door",
                        ]) );

        create_door("east","west",([
                "keyword":({"white door","door"}),
                "status":"closed",
                "c_desc":"一個白色的門",
                "c_name":"白玉門",
                "name":"white jade door",
                "desc":"a white jade door",
                        ]) );
        set("c_item_desc",([
		"photos":" 你看到一張張歷代鳥人族英雄的肖象，一個個威風凜凜。\n",
                        ]) );
    reset();
}//end of creat


int clean_up()
{

      return 0;
}

