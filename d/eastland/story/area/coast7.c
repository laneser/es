#include "../story.h"

inherit ROOM;
int be_pick=0;
void create()
{
        ::create();
	set_short("叢林");
	set_long(@LONG
你來到了一處熱帶叢林區，四周滿是高及頭頂的蕨類植物，這裡的熱氣快要使
得你昏倒在地，更兼藏身在植物裡的小蟲，不住地叮著你的全身，令你難過已極！
或許，找個清涼的地方休息一下，再繼續走，會好過一點。站在這裡，不時聽到陣
陣野獸的叫聲，那聲音，駭人已極，真是個危險的地方。
LONG
	);
	set("exits", ([ 
           "north" : SAREA"coast3"
        ]) );
        set("objects", ([
           "patient" : SMOB"patient1"
        ]) );
	reset();
}
void init()
{
    add_action("do_search","search");
    add_action("do_pick","pick_up_some");
}
int do_search(string arg)
{
    if ( be_pick ) return 0;
    write("你發現幾根奇怪的長藤，長藤是中空的，或許你可以撿幾根(pick_up_some)做為吸管！\n");
    return 1;
}
int do_pick(string arg)
{
    object straw;
    if ( be_pick ) return 0;
    be_pick=1;
    write("你利用長藤做根長長的吸管．．\n");
    straw=new(SITEM"straw");
    straw->move(this_object());
    call_out("back",300);
    return 1;
}
void back()
{
   be_pick=0;
}