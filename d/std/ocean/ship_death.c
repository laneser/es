#include <mudlib.h>

#define ROOM_OBJ "/d/std/ocean/room_death"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Bluesand", "藍沙港", "/d/noden/bluesand/jetty", 30, 70 }),
	({ "Deathland", "死亡大地", "/d/deathland/main/d1", 30, 70 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "ship of darkmerchant", "黑暗商人號" );
	add( "id", ({ "ship", "darkmerchant" }) );
	set_short( "黑暗商人號" );
	set( "long","@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 100000 );
	loc = 0;
	arrive();
}

string query_c_long()
{
	return
		"這是一艘叫做黑暗商人號的破船，你如果想要搭乘黑暗商人號，可以\n"
		"用 board 指令搭船。\n"
		"黑暗商人號的下一個目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->move_player( ROOM_OBJ, ({
		"%s走上黑暗商人號。\n",
		"%s從碼頭登上黑暗商人號。\n" }) );
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
		"黑暗商人號的水手大叫: 二十秒後開船！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"黑暗商人號的水手大叫: 二十秒後開船！下一個目的地是" + schedule[next_loc][1] + "，要上船的旅客請趕快！\n");
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
		"黑暗商人號的水手大叫: 開船羅！\n"
		"你感到船身一陣輕微的震動，黑暗商人號離開了碼頭 ....\n" );
	tell_room( environment(this_object()), 
		"黑暗商人號的水手大叫: 開船羅！\n"
		"黑暗商人號緩緩地開出港口，航向遼闊的大海 ....\n");
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
		"黑暗商人號的水手大叫: " + schedule[loc][1] + "到羅！\n" );
	tell_room( environment(this_object()), 
		"你看到黑暗商人號緩緩地開進碼頭 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}

