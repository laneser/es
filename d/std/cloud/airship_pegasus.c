#include <mudlib.h>
#define ROOM_OBJ "/d/std/cloud/room_pegasus"

inherit OBJECT;

int loc;
mixed *schedule = ({
	({ "Easta", "若嵐城", "/d/eastland/8,5.east", 20, 45 }),
	({ "Nodania", "諾達尼亞城", "/d/noden/6,8.noden", 20, 45 })
});

void announce();
void lets_go();
void arrive();

void create()
{
	seteuid(getuid());
	set_name( "airship pegasus", "天馬號飛船" );
	add( "id", ({ "airship", "pegasus", "ship" }) );
	set_short( "天馬號飛船" );
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
		"這是一艘叫做天馬號的飛船，她有三根巨大的桅杆，碧藍色巨帆閃耀著\n"
		"一點一點的亮光，你如果想要搭乘天馬號號，可以用 board 指令搭船。\n"
		"飛馬號的收費是每人 250 枚銀幣。\n"
		"飛馬號的下一個目的地是" + schedule[(loc+1)%sizeof(schedule)][1] + "。\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return notify_fail("Syntax: board <what>\n");
	if( !wizardp(this_player()) && !this_player()->debit( "silver", 250 ) ) {
		write( 
			"搭乘天馬號飛船需要 250 枚銀幣，可是你錢不夠。\n");
		return 1;
	} else {
		write( 
			"你付給船長 250 枚銀幣，登上天馬號飛船。\n");
	}
	this_player()->move_player( ROOM_OBJ, ({
		"%s登上天馬號飛船。\n",
		"%s登上天馬號飛船。\n" }) );
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
		"天馬號船長大叫: 二十秒後起飛！下一站是" + schedule[next_loc][1] + "！\n" );
	tell_room( environment(this_object()), 
		"天馬號船長大叫: 二十秒後起飛！下一個目的地是" + schedule[next_loc][1] + "，每個人只要 250 枚銀幣！\n" );
	call_out( "lets_go", 20 );
}

// This function flys the ship into the cloud.
void lets_go()
{
	int next_loc;
	object ship_room;

	next_loc = (loc+1)%sizeof(schedule);
	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	tell_room( ship_room, 
		"天馬號船長大叫: 起飛啦！\n"
		"你感到飛船慢慢飄離地面，天馬號飛了起來 ....\n" );
	tell_room( environment(this_object()), 
		"天馬號船長大叫: 起飛啦！\n"
		"天馬號緩緩地升離地面，飛向遼闊的天空 ....\n" );
	call_out( "arrive", schedule[loc][4] );
	ROOM_OBJ->set_location( "cloud" );
	loc = next_loc;
}

// This function flys the ship into the ground.
void arrive()
{
	object ship_room;

	ship_room = find_object(ROOM_OBJ);
	if( !ship_room ) ROOM_OBJ->frog(); // Load the ship room
	ship_room = find_object(ROOM_OBJ);

	ROOM_OBJ->set_location( schedule[loc][0], schedule[loc][2] );
	tell_room( ship_room, 
		"你感到飛船開始慢慢下降，一陣輕微的震動後，飛馬號平穩地著陸了。\n\n"
		"天馬號船長大叫: " + schedule[loc][1] + "到羅！\n" );
	tell_room( environment(this_object()), 
		"你看到巨大的飛船天馬號緩緩地由天而降，平穩地停在你面前的空地上 ....\n" );
	call_out( "announce", schedule[loc][3]-10 );
}
