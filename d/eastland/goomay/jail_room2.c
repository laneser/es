#include "goomay.h"
inherit DOORS;
inherit ROOM;
int move;

void create()
{
        ::create();
        set( "move", 0);
        move = 0;
        set_short("牢房" );
        set_long(
@LONG
這裡是捕快們關犯人的地方，犯了案的犯人都關在這裡，簡簡單單的
牢房裡只有一張稻草鋪成的床，牢房中充斥著黴腐與死亡的氣息，。這裡
黑黝黝的，空氣又差，你真想趕快出去。
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        set( "c_item_desc", ([  "bed" : "@@msg_bed",
                                "hole"  : "@@msg_hole",  ]) );
      create_door("north","south",
            ([  "keyword" : ({"door"}),
                "name"    : "Iron door",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}

void init()
{
    add_action("to_move_bed", "move");
    add_action("to_enter_hole", "enter");
}

string msg_hole()
{
    if( !move )
      return ("你想看什麼？\n");

    return ( 
      "裡面烏漆麻黑的，不知道會有甚麼，也許你可以進去試試看。\n");
}
string msg_bed()
{
    if( !move )
      return ("一張稻草床。\n");

    return (
      "一張稻草床，現在被搬離原來的地方，而露出一個洞。\n");

}

int to_move_bed( string arg )
{
    string dir;
    if( !arg )
      return notify_fail("move what ?.\n");
    if( arg=="bed" ) {
	if (!move)
	{
        write(
          "你把稻草床向旁一推，輕易的就把它推開，露出一個黑黝黝的洞。\n");
        move = 1;
        set( "move", 1);
		return 1;
	}
      else 
	{
        write(
          "你把稻草床推回原位。\n");
        move = 0;
        set( "move", 0);
		return 1;
	}
      return 1;
    }
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" || !move )
      return notify_fail("Enter what?\n");
    if( move )
      this_player()->move_player(Goomay"tunnel1.c","SNEAK");
    return 1;
}

void reset()
{
    ::reset();
    set( "move", 0);
    move = 0;
}
