
inherit "std/map";

void create()
{
	seteuid( getuid() );
	set_name( "map", "地圖" );
	set_short( "a magical map", "魔法地圖" );
	set_long(
		"This is a magical map of the realms of Noden Kingdom. You can either\n"
		"\"read map\" to see the map or \"read legend\" to see what the symbol\n"
		"on the map means.\n",
		"這是一張魔法地圖，你可以 read map 看地圖內容，或用\n"
		"read legend 看地圖上符號所代表的意義。\n"
	);
	set_size( 7, 7 );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
