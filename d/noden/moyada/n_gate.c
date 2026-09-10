//#pragma save_binary

// minor fixes, word usage, grammers.. -Elon 03-10-94
#include "moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("North Gate of Moyada", "摩亞達北門");
	set_long( @LONG_DESCRIPTION
你現在站在摩亞達城的北門，摩亞達城並沒有城牆，但是整個城
除了北西兩個城門以外，都被一道奇特的魔法結界圍住，平常的人可
以自由進出結界，但是懷有敵意的人則無法通過結界。往南一條筆直
的石板路通往城中心的圓形廣場與「銀色之塔」。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"south" : MOYADA"mainrd1.c", 
		"north" : "/d/noden/5,12.noden" ]) );
    set( "pre_exit_func", ([
      "south" : "to_enter",
    ]) );
    set( "no_monster", 1);
    set( "objects", ([
      "guard#1" : MOYADA"monster/moyada_guard",
      "guard#2" : MOYADA"monster/moyada_guard",
    ]) );
	reset();
}

int to_enter()
{
    if( !present("guard") || 
        (this_player()->query("alignment") > -2000) ||
        ((string)this_player()->query("class") == "mage") )
      return 0;
    tell_object( this_player(),
      "守衛說: 抱歉! 你不能通過。\n守衛阻止你進入莫亞達鎮。\n"
    );
    tell_room( environment(this_player()),
      "守衛阻止"+this_player()->query("c_name")+"進入莫亞達鎮。\n",
      this_player()
    );
    return 1;
}
