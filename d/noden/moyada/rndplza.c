//#pragma save_binary

#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
    object *obs, ob;
	::create();
	set_short("圓形廣場");
	set_long( @LONG_DESCRIPTION
你現在站在摩亞達城最著名的圓形廣場，這是摩亞達城最著名的地方。
你可以看到很多對魔法有興趣的人聚集在這裡，他們談論著一些有關於魔法
的話題——咒文、卷軸等等。「銀色之塔」(silver tower)就在廣場的正中
央，它是一棟銀色的圓形建築物，你看到有一個很大的鐵門可供出入。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"south" : MOYADA"mainrd7.c", 
		"west"  : MOYADA"mainrd6.c", 
		"north" : MOYADA"mainrd5.c", 
		"east"  : MOYADA"mainrd8.c",
	]) );
	set( "item_desc", ([
      "tower" : "一棟銀色的圓形建築物，也許你可以進去(enter)看看。\n",
	]) );
	reset();
}

void reset()
{
    object ob;
    if( !present("vendor", this_object()) ) {
      ob = new( "/obj/vendor" );
      ob->set("no_attack", 0);
      ob->set_natural_weapon(20, 10, 20);
      ob->set_natural_armor(40, 10);
      ob->set("max_hp", 200);
      ob->set("hit_points", 200);
      ob->set("exp_reward", 300);
      ob->set("wealth", ([ "silver" : 20 ]) );
      ob->move( this_object() );
    }
    ::reset();
}

void init()
{
    add_action("to_enter","enter");
}

int to_enter( string arg )
{
    object player;
    player = this_player();
    
    if( !arg || arg != "tower" )
      return notify_fail("Enter what?\n");
    tell_room( this_object(), 
      sprintf("%s走進塔內。\n", player->query("c_name") ), player );
    player->move_player("/d/mage/tower/mage_guild","SNEAK");
    tell_room( environment(player), 
      sprintf("%s(%s)走了進來。\n", player->query("c_name"),player->query("name") ), player );
    return 1;
}
