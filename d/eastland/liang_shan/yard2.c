#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "庭院" );
	set_long(
	"這是一個小小的庭院，安靜而且典雅，濃蔭如傘，木葉之外有蟬聲搖曳，\n"
	"卻顯得天地更為寂靜，紅塵中的喧鬧煩囂，似已久未入庭院。北邊有一個小\n"
	"小的建築。西邊有一座精緻的竹製涼亭(shed)。\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set( "c_item_desc",(["shed":
        "這是一座精巧的小涼亭，完全用青竹製成，亭內有一個書生打扮的人，正\n"
        "低頭不知在觀看什麼? 也許你可以進去(enter)看看....\n"
        ]));
        set( "exits", ([
                "north"  : TROOM"bed6",
                "east" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "shed")
    return notify_fail(
    "你想要進去那兒?\n");
    write (
    "你順著小小的階梯，緩緩步入了涼亭\n");
    tell_room(this_object(),
	"你看到"+this_player()->query("c_name")+"信步走進了涼亭內。\n",
    this_player());
    this_player()->move_player(TROOM"shed","SNEAK");
   return 1;
}
int clean_up() { return 0; }    
