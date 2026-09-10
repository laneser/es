#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("樹林");
	set_long( @LONG
你置身在一片裡，樹枝遮住了射照下來的光線，顯得有點陰涼。這樹林裡不時
有鳥類啾鳴的聲音，另外還有些動物隱藏其中。在你北邊還有間小小的茅屋(house
)，那茅屋不怎麼起眼，你可以進去看看(enter)，南邊則是東郊。
LONG
	);
	set( "exits", ([ 
            "south" : SCITY"plain1",
        ]) );
	reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
      return notify_fail("你要進入那裡?\n");
      this_player()->move_player(SCITY"house3",({
                     "%s進入了一間小茅屋。\n",
                     "%s從外面走了進來.\n"}),"");
      return 1;
}