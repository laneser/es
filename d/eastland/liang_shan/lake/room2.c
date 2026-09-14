#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你走進了一間普通的房子，雖然窄小，但卻打掃的一塵不染。牆角\n"
	"放了一個大水缸(cistern)，裡面好像盛滿了清水，不知是幹嘛用的?\n"
	  );
        set("c_item_desc",(["cistern":
"你走到水缸邊，仔細觀察這個水缸，你發現水缸中有許多美麗的小魚，正在\n"
"缸中游來游去，好像很快樂的樣子。你突然有一種想拿東西餵它們的衝動。\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village1"
        ]) );
        	set( "pre_exit_func",([
	        "east" :"check_feed"
	        ]));
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "cistern")
    return notify_fail(
    "你想要進去那兒?\n");
    write (
    "你走到水缸邊，很勉強的把自己塞進水缸，喝了幾口水後，你開始打量\n"
    "新環境。\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "一頭鑽進水缸裡。\n" ,
    this_player());
    this_player()->move_player("/d/eastland/liang_shan/lake/cistern","SNEAK");
   return 1;
}
int check_feed()
{    
object fisher;
if ( !(int)this_player()->query_temp("feed_fish")==1 || present("fisher") ) return 0;
write(
"突然間，一個人急急忙忙的衝了進來，差點把你撞倒，於是你停下來準備跟他理論..\n"
"這個冒失鬼忙陪笑道: 對不起，我只是趕回來釣魚，不過看起來，你好像已經釣了吧。\n"
"真是謝謝你了...\n");
fisher =new("/d/eastland/liang_shan/monster/fisher1");
fisher->move(TROOM"room2");
this_player()->delete_temp("feed_fish");
return 1;
}
    