
#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_ta_tong"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "Ship of Ta-Tong", "大通號漁船");
	add( "id", ({ "ship", "ta-tong" }) );
	set_short("大通號漁船");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你現在正站在大通號漁船的甲板上，大通號是一艘十分陳舊的漁船，\n"
"原本是用來在海威港近海捕魚，但是最近東方和死亡大地的交通越來越\n"
"頻繁，所以船老大就改行當船伕，於是老舊的大通號就成了渡輪。\n";
	switch( location ) {
		case "Deathland":
			long += "    大通號現在正停泊在死亡大地的碼頭上。\n";
			break;
		case "Haiwei":
			long += "    大通號現在正停泊在海威港的碼頭邊。\n";
			break;
		case "ocean":
		default:
			long += "    大通號現在正在一望無際的大海上掙扎。\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="ocean" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/ocean/ocean" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}

