#include <mudlib.h>
#define SHIP_OBJ "/d/std/cloud/airship_pegasus"

inherit ROOM;
string location;

void create()
{
	::create();
//	set_name( "airship pegasus", "天馬號帆船");
	add( "id", ({ "airship", "pegasus" }) );
	set_short("天馬號帆船");
	set( "long","@@query_c_long" );
	set( "light", 1 );
	set_outside( "cloud" );

	reset();
}

string query_c_long()
{
	string long;

	long = 
"你現在正站在天馬號飛船的甲板上，三根巨大的桅杆撐起兩幅碧藍色的巨帆，佔\n"
"去了飛船後方一大半的空間，這艘飛船原本是默爾斯人進貢東方大國皇帝的禮物，不\n"
"過由於皇帝對默爾斯人並不信任，這艘飛船輾轉到了一個諾達尼亞商人的手中，現在\n"
"它已經成了富有的旅行者最方便快速的交通工具。\n";
	switch( location ) {
		case "Easta":
			long += "    天馬號現在正停在若嵐城西門外的載客站。\n";
			break;
		case "Nodania":
			long += "    天馬號現在正停在諾達尼亞城外的載客站。\n";
			break;
		case "cloud":
		default:
			long += "    天馬號現在正飛在遼闊的天空中。\n";
			break;
	} 
	return long;
}

// This function sets the location of the ship.
varargs void set_location( string new_loc, string exit )
{
	location = new_loc;
	if( location=="cloud" || !exit ) {
		set( "exits", ([]) );
		SHIP_OBJ->move( "/d/std/cloud/cloud" );
	} else {
		set( "exits", ([ "out": exit ]) );
		SHIP_OBJ->move( exit );
	}
}
