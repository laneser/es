
#include <mudlib.h>
#define SHIP_OBJ "/d/std/ocean/ship_death"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "ship of darkmerchant", "黑暗商人號");
	add( "id", ({ "ship", "darkmerchant" }) );
	set_short("黑暗商人號");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "ocean" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你現在正站在黑暗商人號的船裡, 一艘有點破舊又不會太破舊的中型船, 一種特殊\n"
"的死藍色摻雜著的灰白色的斑點, 更顯得這艘船似乎將駛向恐怖的地方。\n";
	switch( location ) {
		case "Bluesand":
			long += "    黑暗商人號現在正停泊在藍沙港的碼頭上。\n";
			break;
		case "Deathland":
			long += "    黑暗商人號現在正停泊在死亡大地的碼頭邊。\n";
			break;
		case "ocean":
		default:
			long += "    黑暗商人號現在正航行在一望無際的大海上。\n";
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
