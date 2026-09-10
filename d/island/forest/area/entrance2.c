#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","河濱");
    set_long(@LONG
展現在眼前的是一片高聳的山壁，平時由遠處就能看得見，旁邊還有一
條清澈的小河流，大概是因為人煙稀少的關係，這條小河還得以維持原來的
風貌。旁邊還有棵茂密的大樹(tree)，它的樹齡應該已經有數百年了吧！
LONG
             );
    set("item_desc",(["tree":@C_LONG
這棵大樹的枝幹向四方延展，末端還密密麻麻的交纏著，長得可真是茂密
呀！陽光幾乎都穿不透；幾隻小鳥停在枝幹上唱歌，突然間樹上的葉子射
出幾道光線在地上，好神奇喔！難道是在和小鳥們對話嗎？
C_LONG
           ]) );
    set("exits",([
            "west":AREA"upriver2",
            "north":AREA"entrance"]) );
    set_outside("island");
    set("objects",([
        "crab#2":"/d/noden/bluesand/monster/crab",
        "crab#1":"/d/noden/bluesand/monster/crab"]) );  
     reset();
}

void init()
{
    add_action("ask_passwd","pray");
}

int ask_passwd(string arg)
{
    if( !arg || arg != "password")
    return notify_fail(
    "樹上的小鳥們對你說：你是要問通行密碼(password)嗎？\n");
    write(@ALONG
          
          突然整個樹的樹葉都射出光芒，在你的面前聚集出一團光球
        
        光球逐漸換化成人型，這一切都太突然了，你看得整個人都楞住了 
        
        不一會兒，樹雷守護靈　船穗　站在你面前，和藹的對你微笑著
        
     船穗 溫柔的說：密碼很簡單的，只要說**芋頭蕃薯**就行了，勇者，去吧！！
        
        漸漸的，光線一條一條的減少了，船穗 隨著光的散去而消失了！

ALONG
                );
    this_player()->set_explore("island#2");
    return 1;
}
