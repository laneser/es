#include "saulin_temple.h"

inherit ROOM;

void create()
{
	object well;
	::create();
	set_short( "藥圃");
	set_long( @C_LONG_DESCRIPTION
這裡是一片寬闊的藥圃，圃中一畦畦的田地種著許多奇奇怪怪的植物，大多
是你從來也沒見過的，不知道天心大師是從哪裡收集來這麼多的藥草？藥圃的東
邊還有一塊空地，是用來種(plant) 新的藥草的，東北角還有一個井(well)，是
藥圃的灌溉水源。
C_LONG_DESCRIPTION
	);
    well = new(SAULIN_OBJ"dry_well");
    well->move(this_object());
    set_outside("eastland");
	set( "exits", ([ "west" : SAULIN"herb_room", ]) );
	reset();	
}

void init()
{
    add_action("climb_well", "climb");
}

int climb_well(string arg)
{
	if( !arg || arg!="well" )
      return notify_fail("爬什麼？\n");
    tell_object( this_player(), 
      "你小心的沿著井緣爬下井底，突然，腳下一個踩空....\n" 
    );
    tell_room( this_object(), 
      this_player()->query("c_cap_name")+
      "試著爬入井底...哎呀! 他頭下腳上的栽進去了，技術實在是 ...\n"
      ,this_player()
    );
    this_player()->move_player( SAULIN"under_well1", "SNEAK" );
    tell_room( environment(this_player()), 
      this_player()->query("c_cap_name") + "從井口直直的栽了下來。\n"
      ,this_player()
    );
    return 1;
}
