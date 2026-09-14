#include <mudlib.h>
#define ROOM_OBJ "/d/std/ocean/room_ta_tong"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Haiwei", "海威港", "/d/eastland/haiwei/jetty", 30, 80 }),
   	({ "Deathland", "死亡大地", "/d/deathland/main/d1", 30, 80 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "Ship of Ta-Tong", "大通號漁船" );
	add( "id", ({ "ship", "ta-tong" }) );
	set_short( "大通號漁船" );
	set( "long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

string query_c_long()
{
	return
		"這是一艘叫做大通號的老舊漁船，你如果想要搭乘大通號，可以\n"
		"用 board 指令搭船。\n"
		"大通號的下一個目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s走上大通號漁船。\n",
		"%s從碼頭登上大通號。\n" }) );
	return 1;
}

// This function announce the ship is sailing in advance (20 seconds)
void announce()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"大通號的船老大大叫: 快要開船啦！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"大通號的船老大大叫: 快開船啦！下一個目的地是" + schedule[next_loc][1] + "，要上船的客人請趕快！\n" );
	call_out( "lets_go", 20 );
}

// This function sails the ship into the ocean.
void lets_go()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"大通號的船老大大叫: 出發羅！\n"
		"你感到大通號像脫韁的野馬般的大搖特搖，大通號離開了碼頭 ....\n" );
	tell_room( environment(this_object()), 
		"大通號的船老大大叫: 出發羅！\n"
		"大通號緩緩地開出港口，航向遼闊的大海 ....\n" );
	call_out( "arrive", schedule[loc][4] );
	ROOM_OBJ->set_location( "ocean" );
	loc = next_loc;
}

// This function sails the ship into the ocean.
void arrive()
{
	object ship_room;

	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][2] );
	tell_room( ship_room, 
		"大通號的船老大大叫: " + schedule[loc][1] + "到羅 ! 人客們趕快下船吧 !\n" );
	tell_room( environment(this_object()), 
		"你看到大通號緩緩地開進碼頭 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}

