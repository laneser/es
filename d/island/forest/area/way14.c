#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("樹林");
    set_long(@LONG
這兒四周長滿了奇形怪狀的植物，大多是目前尚不為人知的。風也已經
和緩多了，不像狹道中那般強勁可怕；四處傳來的是一連串的悅耳鳥鳴，偶
而出現幾聲令人膽寒的低鳴，不知道何處會出現可怕的怪物呢！南邊的草叢
(thicket)中似乎有點古怪！
LONG
             );
    set("exits",([
            "north":AREA"way13"]) );
    set_outside("island");
    set("c_item_desc",(["thicket":@HOLE

           哇！！！原來這兒有個洞耶，大概可以鑽進去(enter)看看！

HOLE
                       ,"hole":@C_LONG
這個洞黑黑窄窄的，看起來似乎有點嚇人；裡面不知道躲了什麼怪物？
C_LONG
                       ]) );
    reset();
}

void init()
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
    object victim;
    
    if( !str || str!="hole" )
         return notify_fail("你要進哪兒？\n");
         write("\n．．你帶著些微的顫抖緩慢的向洞中滑步前進．．\n\n");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"蹲下身來，用力把自己擠進洞中！\n"
           ,this_player() );
         this_player()->move_player(AREA"hole1","SNEAK");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"用力的將自己的身軀給擠了進來！\n"
           ,this_player() );
         return 1; 
}
