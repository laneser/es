//traroom.c
#include "hawk.h"
inherit ROOM;
int potion;
int mirror;
void create()
{
        ::create();
        set_short("漂亮的房子");
        set_light(1);
        set_long( @LONG_DESCRIPTION
這是一棟裝璜十分闊氣的房子，看起來像是有錢人家住的地方。牆邊擺了一
個大大的書櫃(closet)，裝了上百本的書，難道這房子的主人是一個飽讀詩書的
讀書人嗎？
LONG_DESCRIPTION
        );
        set( "exits", ([
                "out" : HAWK"room2-11",
                     ]) );
        set( "objects", ([
                "traito" : MOB"traito",
               "servant" : MOB"servant"])
                        );
        set("c_item_desc",([
                "closet":"@@to_closet"
                        ]) );
        reset();
}//end of creat

string to_closet()
{
        return "這是一個很大的書櫃，裡面裝了上百本的書，不過看起來書的後面\n"
                +"應該還有一些空間，不知道放了些什麼東西。\n\n";
}

void init()
{
        add_action("to_search","search");
}

int to_search(string str)
{
        object obj,obj2;
        if (!str) return 0;
        if (str == "box")
        {
                if (this_player()->query_temp("smore_box") != 1)
                {
                        tell_object(this_player(),"你找了又找，並沒有發現任何東西。\n");
                        return 1;
                }

                if ( present("traito",this_object()) )
                {
                        tell_object(this_player(),"雷多瞪了你一眼。\n");
                        return 1;
                }
                else
                {
                        tell_object(this_player(),"你在雷多的鐵箱子裡找到一瓶橙色的藥水。\n");
                        obj = new(OBJ"potion");
                        obj->move(this_object());
                        potion = 0;
			this_player()->set_explore("noden#42");
                        this_player()->set_temp("smore_box",2);
                        return 1;
                }
                return 1;
        }
        if (str == "closet")
        {
                if (mirror == 0) return 0;
                tell_object(this_player(),"你在書櫃中找到一面鏡子。\n");
                obj2 = new(OBJ"mirror");
                obj2->move(this_object());
                mirror = 0;
                return 1;
        }
        return 1;
}


void reset()
{
        ::reset();
        potion = 1;
        mirror = 1;
}
