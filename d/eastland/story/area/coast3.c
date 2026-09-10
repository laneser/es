#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("叢林");
	set_long(@LONG
你來到了一處熱帶叢林區，四周滿是高及頭頂的蕨類植物，這裡的熱氣快要使
得你昏倒在地，更兼藏身在植物裡的小蟲，不住地叮著你的全身，令你難過已極！
站在這裡，不時傳來陣陣海浪的聲音，原來在你西邊是一處白沙灘。
LONG
	);
	set( "exit_suppress", ({
	   "south"}) );
	set("exits", ([ 
       	    "east" : SAREA"coast4", 
            "west" : SAREA"coast1",
           "south" : SAREA"coast7" 
        ]) );
	set("objects", ([
           "insect#1" : SMOB"insect1",
	   "insect#2" : SMOB"insect1",
           "insect#3" : SMOB"insect1"
	]) );
	reset();
}
void init()
{
    add_action("do_search","search");
}
int do_search( string arg )
{
    write("你找了找發現在南邊(south)似乎有條通道！\n");
    return 1;
}