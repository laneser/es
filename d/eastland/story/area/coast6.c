#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("叢林");
	set_long(@LONG
你來到了一處熱帶叢林區，四周滿是高及頭頂的蕨類植物，這裡的熱氣快要使
得你昏倒在地，更兼藏身在植物裡的小蟲，不住地叮著你的全身，令你難過已極！
或許，先找個清涼的地方休息一下，再繼續走，會好過一點。在你東方是一塊小草
原。
LONG
	);
	set("exits", ([ 
             "east" : SAREA"plain1",
       	    "north" : SAREA"coast4" 
        ]) );
        set("objects", ([
           "insect#1" : SMOB"insect1",
           "insect#2" : SMOB"insect1",
           "insect#3" : SMOB"insect1",
           "insect#4" : SMOB"insect1",
        ]) );
	reset();
}
