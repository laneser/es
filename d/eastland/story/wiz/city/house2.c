#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("私塾");
	set_long( @LONG
這裡是「巫咸城」里人民學習知識的地方。私塾裡除了桌椅之外，四周牆壁上
還掛有幾張潑墨山水畫和幾貼真跡。不但學子們正聚精會神地聆聽教誨，教師更認
真地傳授眾人的知識。在空氣中，「子曰子曰」的朗誦聲音此起彼落，課堂裡端得
是嚴肅無囂的氣氛。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"nw2"
        ]) );
        set("objects", ([
             "teacher":SWMOB"teacher1",
           "student#1":SWMOB"student1",
           "teacher#2":SWMOB"student1",
           "teacher#3":SWMOB"student1",
        ]) );
	reset();
}
