#include "/d/eastland/legend/legend.h"

inherit ROOM;
inherit LAKE"in_swamp";
int be_search,be_dig;

void create()
{
        ::create();
    set_short("沼澤");
        set_long( 
@LONG
啊！毒氣，糟糕，你走進了最危險的沼澤地，四周都是足以致命的瘴氣。但是
奇怪的是，這裡不像其他沼澤地充滿各式各樣吃人的巨型怪物，也沒有人類的骸骨
，相反的，這裡到處都是巨型沼澤怪獸的殘骸；雖然你已經站在這裡好一段時間，
但卻沒有任何一隻怪物追來。你四下搜尋，發現的空氣中瀰漫著一股濃厚的血腥惡
臭，這股惡臭比沼氣更刺鼻，更難聞，而且每隔一段時間就傳來一陣怪嘯，聲音有
如牛哞，但卻遠比其響亮。你想，一定是更恐怖的怪物。
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south","down"}) );
    set("exits",([
            "east":LAKE"swamp7",
           "north":LAKE"swamp7",
            "west":LAKE"swamp7",
           "south":LAKE"swamp8",
            "down":LAKE"swamp_d1"
    ]) );
    be_search=0;
    be_dig=0;
    reset();
}
void init()
{ 
    ::init();
    add_action("do_search","search");
    add_action("do_shake","shake");
}
int do_search(string arg)
{
    if ( be_search ) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    tell_object(this_player(),
       "你找到一棵「三珠樹」(tree)，搖搖(shake)它說不定會有什麼東西掉下來。\n");
    be_search=1;       
    set("c_item_desc",([
          "tree":
"       這是一棵光明燦爛的樹，這樹的形狀有點像柏樹，樹葉都是些\n"
"       明亮的珍珠，從樹身的兩旁對稱地生出兩枝樹幹，和主幹並而\n"
"       為三，遠遠望去，有點像彗星的尾巴。\n"
    ]) );                     
    return 1;
}
int do_shake(string arg)
{ 
    object fruit;
    if (!arg || arg!="tree") return 0;
    if (!be_search) return 0;
    if (be_dig) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    be_dig=1;
    this_player()->delete_temp("mobs");
    tell_object(this_player(),
        "你用力搖「三珠樹」，結果，從樹葉掉下一顆紅色的果實！\n");
    fruit=new(LITEM"fruit");
    fruit->move(this_object());
    delete("c_item_desc/tree");
    call_out("do_recover",300);
    return 1;
}
void do_recover()
{
    be_search=0;
    be_dig=0;
}
void reset()
{
    be_search=0;
    be_dig=0;
    delete("c_item_desc/tree");
    ::reset();
 }