#include "island.h"

#define ROOM_OBJ "/d/island/7,2.island"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({  "noden", "/d/noden/6,6.noden", 60, 120 }),
	({  "eastland", "/d/eastland/18,10.east", 60, 120 })
                   });

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
//	set_name( "gate","遁甲之門" );
	set("name","gate");
	add( "id", ({ "gate" }) );
	set_short( "遁甲之門" );
	set_long(@LONG
這是傳說中仙人用奇門遁甲之術，所造出的門，在西方就是所謂的傳送
術，雖然說是門，但這是找不到特定名詞才這麼說的，事實上它不過是
個閃著光芒的長方形框框，聽說它會在不同的時間出現在不同地方，想
進去的話用進入(enter)試試看。
LONG
 );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

void init()
{
	add_action( "do_enter", "enter" );
}

int do_enter(string arg)
{
	if( !arg || !id(arg) ) 
	{
	write(@LONG
	
你要進入啥東東呀？

LONG
              );
	return 1;
	}
	else
	{
	write(@LONG
	
跨過遁甲之門，你到達另一個新的空間。

LONG

            );
	this_player()->move_player( ROOM_OBJ,
		"\n"+this_player()->query("c_name")+"進了遁甲之門。\n",
	        "\n"+this_player()->query("c_name")+"從遁甲之門進來了。\n" );
	return 1;
	}
}

void announce()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()),"\n遁甲之門的形體漸漸模糊。\n\n" );
	call_out( "lets_go", 20 );
}

void lets_go()
{
	int next_loc;
	object gate_room;

	next_loc = (loc+1)%sizeof(schedule);
	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	tell_room( environment(this_object()), "\n周圍的空間恢復原樣，遁甲之門不見了。\n\n" );
	call_out( "arrive", schedule[loc][3] );
	ROOM_OBJ->set_location( "virtual" );
	loc = next_loc;
}

void arrive()
{
	object gate_room;

	gate_room = find_object(ROOM_OBJ);
	if( !gate_room ) ROOM_OBJ->frog(); // Load the room
	gate_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][1] );
	tell_room( environment(this_object()),"\n周圍的空間開始扭曲，遁甲之門逐漸形成了\n\n" );
	call_out( "announce", schedule[loc][2]-20 );
}

