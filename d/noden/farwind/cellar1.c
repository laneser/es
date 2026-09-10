//#pragma save_binary
 
#include "farwind.h"
 
inherit ROOM;
 
void create()
{
        ::create();
        set_short( "酒窖" );
        set_long(@C_LONG
這裡是一間酒窖，即使這裡一片漆黑伸手不見五指，你也可以很清
楚地確定這點，因為濃冽的酒味幾乎把你給醉倒。角落裡有一個生鏽的
鐵梯子(ladder)，似乎是離開這裡唯一的路。
C_LONG
        );
        set( "item_desc", ([
        "ladder" : "這個梯子上面生滿了鐵鏽，似乎這裡的主人也很少下來\n"
                   "這個酒窖。梯子的旁邊有一個洞(hole)，不知道裡面有\n"
                                        "什麼？\n",
        "hole" : "這個洞雖然不大，但是你勉強可以鑽進去(enter)。\n"
        ]) );
        set( "exits", ([
                "up" : FARWIND"smithy"
        ]) );
        set( "pre_exit_func", ([
                "up" : "check_ladder"
        ]) );
        set( "objects", ([
                "rat 2" : FARWIND"monster/rat"
        ]) );
        reset();
}
 
void init()
{
        if( this_player()) this_player()->set_explore("noden#1");
        add_action( "enter_hole", "enter" );
}
 
int check_ladder()
{
        object smithy;
 
        smithy = find_object( FARWIND"smithy" );
        if( !smithy || !smithy->query("item_desc/ladder") ) {
                write(
                "你爬到梯子頂端，但是上面似乎被什麼重物壓住了，你無法出去。\n"
                );
                return 1;
        }
        return 0;
}
 
 
int enter_hole(string arg)
{
        string name;
        if( !arg || arg!="hole" )
                return notify_fail("進入什麼？\n");
        name=(string)this_player()->query("c_name");
        this_player()->move_player(FARWIND"cellar2",
                name+"爬進梯子旁的一個小洞。\n",
                name+"從一堆箱子後面走了出來。\n"
         );
        return 1;
}
 
