#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
這是一處透著些許微光線的陰暗洞穴。從西面吹進來的風在地上繞著圈圈形成
一個小小的龍捲風旋即又飛起以其利銳的前鋒刮過牆壁發出「咻咻咻」的聲音；在
空中，好似有人正在對著你嘲笑並且發出桀桀的笑聲，那異樣的感覺，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麼東西，低頭一看，竟然是一堆白骨！看
來這不是個良善的地方，你還是快離開這裡為妙。
LONG
	);
	set("exits", ([
             "west" : SAREA"vhole1",
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_open","open");
    add_action("do_search","search");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("這裡受妖法控制使得你無法做這樣動作！\n");
    return 1;
}
int do_search(string arg)
{
    if ( query("be_open") )
       write("你發現一口被人打開過的棺材(coffin)。\n");
    else write("你發現一口棺材(coffin)，似乎可以打開(open)。\n");
    return 1;
} 
int do_open(string arg)
{
    object ob;
    if (!arg||arg!="coffin") return notify_fail("你要打開什麼東西?\n");
    if ( query("have_vampire") || query("be_open") ) { 
       write("這口棺材業已被人打開過了。\n");
       return 1;
    }
    write("\n\n忽然，從棺材中蹦出一個僵□！\n\n\n");
    ob=new(SMOB"vampire1");
    ob->move(this_object());
    SAREA"vhole1"->set("have_vampire",1);
    SAREA"vhole2"->set("have_vampire",1);
    SAREA"vhole3"->set("have_vampire",1);
    set("be_open",1);
    return 1;
}
int clean_up()
{
    return 0;
}
void reset()
{
    set("be_open",0);
    ::reset();
}