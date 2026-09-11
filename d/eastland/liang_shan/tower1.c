#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "瞭望臺" );
	set_long(
	"這裡是梁山泊山寨的瞭望臺，用粗大的檜木架成，雖然強風不斷，\n"
	"站在上面仍然如履平地．角落放著一臺千里鏡(telescope)．\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );
        set("c_item_desc",(["telescope":
"這是默爾斯帝國進貢的千里鏡，透過它可看到很遠的地方．最近被梁\n"
"山泊的好漢們搶來，目前它正對著幽國城的方向以便監視官兵動靜．\n"
"也許你可以試著去使用(use)它．\n"            
            ]));        
        set( "exits", ([
                "down" : TROOM"wall8"
        ]) );
        set( "objects",([
                "lu":TMONSTER"lu",
                "bandit":TMONSTER"small_bandit",
                "captain":TMONSTER"captain"
                ]));
        reset();
}
void init()
{
     add_action("do_use","use");
}
int do_use(string arg)
{
 if ( !arg || arg != "telescope")
    return notify_fail(
    "用什麼?\n");
    write (
    "你將眼睛湊近千里鏡，幽國城繁華的市街浮現於你眼前．\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "使用千里鏡，並且露出不可思議的表情\n" ,
    this_player());
return 1;
}
int clean_up() { return 0; }    