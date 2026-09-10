#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("小茅屋");
	set_long( @LONG
一進到這裡，你就發現滿屋子裡擺滿了許許多多五花八門，琳朗滿目的東西；
首先，在右邊的櫃子裡分別擺滿了壺、杯、瓶、盆和碗等容積類的東西，上面的漆
多是唐朝時代的；左邊分別陳列了各式各樣的武器，短刀乃至於長劍，通通都有，
每一件都隱隱有著異樣的光芒；前面的几案上則是一些玉、如意、小動物之類；另
外有一竹簍盛滿了卷軸、書籍和書法筆墨真貼。各式各樣的東西令這裡感到相當擁
擠。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "out" : SCITY"plain2"
        ]) );
        set("objects", ([
           "older":SWMOB"golden_older",
        ]) );
	reset();
}
