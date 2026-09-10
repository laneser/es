#include "../story.h"

inherit ROOM;
int bone=1;
int i=0;
void create()
{
        ::create();
	set_short("洞穴");
	set_long( @LONG
這是一處透著些許微光線的陰暗洞穴。從上面灌進來的風在地上繞著圈圈形成
一個小小的龍捲風旋即又飛起以其利銳的前鋒刮過牆壁發出「咻咻咻」的聲音；在
空中，好似有人正在對著你嘲笑並且發出桀桀的笑聲，那異樣的感覺，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麼東西，低頭一看，竟然是一堆白骨(bone
)！看來這不是個良善的地方，你還是快離開這裡為妙。
LONG
	);
	set( "exits", ([ 
       	        "up" : SAREA"vhole1",
       	      "down" : SAREA"room_t",
        ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
    add_action("do_search","search");
}
void qq()
{
    bone=1;
}
void rr()
{
   i++;
   if ( i < 2 ) return ;
   i=0;
   call_out("qq",3600);
   return ;
}
int do_search(string arg)
{
    object head,tail;
    if ( !arg || arg !="bone" ) return 0;
    if ( !bone ) {
       tell_room(this_object(),"這堆白骨已經被人找過了 ! \n");
       return 1;
    }
    tell_room(this_object(),"\n突然從白骨堆裡蹦出一隻妖怪來 ! \n\n");
    head=new(SMOB"head");
    tail=new(SMOB"tail");
    head->set("other",tail);
    tail->set("other",head);
    head->move(this_object());
    tail->move(find_object_or_load(SAREA"room_t"));
    bone=0;
    return 1;
}