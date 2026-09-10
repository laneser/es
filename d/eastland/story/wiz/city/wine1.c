#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「悅來客棧」");
	set_long( @LONG
「悅來客棧」在「巫咸城」可說是最大的一間客棧，老闆夥計和藹可親，價錢
公道，平時生意相當不錯，門庭若市，座無虛席，漸漸地，名聲傳了開來，許多到
過「巫咸城」觀光的旅客都會來這裡品□佳餚美酒，順便或多或少打聽一些消息。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ee",
        ]) );
        set("objects", ([
           "captain":SWMOB"wiz_captain2"
        ]) );
	reset();
}
