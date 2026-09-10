// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;
int find;

void create()
{
	::create();
	set_short("垃圾坑");
	set_long( @C_LONG_DESCRIPTION
這裡似乎已是蟻穴的底部，到處堆著巨蟻們的廢棄物。排洩物(excreta)、
食物殘渣(dump)，那臭味令你難受極了，你只想儘快的離開這裡。
C_LONG_DESCRIPTION
	);
	set( "objects", ([
	   "yellow slime"   : MOYADA"monster/yellow_slime",
	   "green slime"    : MOYADA"monster/green_slime",
	   "red slime"      : MOYADA"monster/red_slime",
	]) );
	set( "search_desc", ([
	  "dump" : "@@search_dump",
	]) );
	set( "item_desc", ([
	  "excreta" : "盡是螞蟻的排洩物，臭死了。\n",
	  "dump" : "螞蟻們吃剩的食物，不曉得它們為何如此浪費。\n"+
	           "仔細一看裡面好像有什麼東西在騷動。\n",
	]) );
	reset();
}

void reset()
{
    ::reset();
    if( !present("metal slime", this_object()) ) find = 0;
}

int search_dump()
{
	object ob;

	if( find ) return 0;
   if( this_player() ) this_player()->set_explore("noden#10");
	ob = new( MOYADA"monster/metal_slime" );
	ob->move( this_object() );
	tell_room( environment(this_object()),
		"突然一隻金屬史萊姆從垃圾堆中跳了出來，對著你微笑。\n" );
	find = 1;
	call_out( "disappear", 200, ob );
	return 1;
}

void disappear(object ob)
{
	object *item;
	int i;

	if( !ob ) return;
	tell_room( environment(ob), 
		"你眼前的金屬史萊姆突然消失了。\n" , ob
	);
	item = all_inventory(ob);
	for( i=0; i<sizeof(item); i++ ) item[i]->remove();
	ob->remove();
}

void init()
{
	add_action("to_climb", "climb");
}

int to_climb( string str )
{
	if( !str || str=="" )
		return notify_fail("你要爬哪個方向?\n");
	if( str != "up" )
		return notify_fail("那個方向不通啦!\n");
	to_climb_up( this_player(), MOYADA"anthill/cellar3", 40 );
	return 1;
}
