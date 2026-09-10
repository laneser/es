#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山頂");
	set_long( @LONG
在這山頂北方的遠處是層巒疊峰，好似一幕幕的綠布不住往天際延伸。天上白
雲離頭頂只不過尺許高度，一抹抹如條素色的被子，像要壓將下來，在東方的天空
還漂浮著一座建築物，像是宮殿之類的。往北俯視，與對山之間銜接著一個溪流，
急湍澎湃，「刷刷」有聲，不知高度若何，否則大可一遊而盡興，此外，尚有一座
吊橋漂浮溪谷上。在你東邊是個斷崖，裡面白茫茫的一片，也不知道有多深。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "down"}) );
	set( "exits", ([ 
            "south" : SAREA"mountain3",
       	    "north" : SAREA"bridge1", 
       	     "west" : SAREA"mountain1",
             "down" : SAREA"vhole1",
        ]) );
        set("goto_palace",1);
        set("can_use_flute",1);
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search()
{
    write("你發現旁邊有個直徑一尺的小洞(hole)指著往下(down)的方向。\n");
    return 1;
}
