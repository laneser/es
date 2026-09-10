
#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
這是一處透著些許微光線的陰暗洞穴。從外面吹進來的風在地上繞著圈圈形成
一個小小的龍捲風旋即又飛起以其利銳的前鋒刮過牆壁發出「咻咻咻」的聲音；在
空中，好似有人正在對著你嘲笑並且發出桀桀的笑聲，那異樣的感覺，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麼東西，低頭一看，竟然是一堆白骨！看
來這不是個良善的地方，你還是快離開這裡為妙。
LONG
	);
        set( "exit_suppress", ({
            "down" }) );
	set("exits", ([
            "out" : SAREA"mountain2",
           "east" : SAREA"vhole3",
           "west" : SAREA"vhole2",
           "down" : SAREA"room_h"
        ]) );
        set("pre_exit_func",([
           "out":"can_pass"]));
	reset();
}
void init()
{
    add_action("do_auction","auction");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("這裡受妖法控制使得你無法做這樣動作！\n");
    return 1;
}
int can_pass()
{
   object vampire;
   if ( vampire=present("the great vampire",this_object()) ) {
       write(sprintf("%s伸出雙手攔住你的去路！\n\n",vampire->query("c_name")));
       return 1;
   }
   return 0;
}
int clean_up()
{
   return 0;
}
