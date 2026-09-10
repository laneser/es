#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
這是一處透著些許微光線的陰暗洞穴。從上面吹進來的風在地上發出「咻咻咻
」的聲音；在空中，好似有人正在對著你嘲笑並且發出桀桀的笑聲，那異樣的感覺
，不禁令你毛骨悚然冷汗直流；忽然，不知道你踢到什麼東西，低頭一看，竟然是
一堆白骨！看來這不是個良善的地方，你還是快離開這裡為妙。咦，怎麼腳底下□
□的？嚇，原來是從左邊的牆壁底下流出些許血水，令這裡益發顯得恐怖。
LONG
	);
	set("exits", ([
           "east" : SAREA"vhole1"
        ]) );
        set("objects", ([
          "bat#1" : SMOB"bat1",
          "bat#2" : SMOB"bat1",
          "bat#3" : SMOB"bat2",
          "bat#4" : SMOB"bat1",
          "bat#5" : SMOB"bat2",
        ]) );
        set( "c_item_desc", ([
          "crack" : "一個十寸大的裂縫，似乎可以擠(squeeze)進去。\n"
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_search","search");
    add_action("do_squeeze","squeeze");
}
int do_squeeze(string arg)
{
    if ( !arg || arg!="crack" )
       return notify_fail("你想把身子擠進那裡去？\n");
    write("你把身子擠進左邊牆壁的一個裂縫中。\n");
    this_player()->move_player(SAREA"waterfall1",({
       "%s把身子擠進入了一個裂縫中。\n",
       "%s從裂縫外面走了進來.\n"}),"");
    return 1;
}
int do_search(string arg)
{
    write("你發現左壁有幾條裂縫(crack)，原來地上的血水是從那裡來的！\n");
    return 1;
}    
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
        write("這裡受妖法控制使得你無法做這樣動作！\n");
    return 1;
}
int clean_up()
{
    return 0;
}