#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
	seteuid( getuid() );
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name( "map", "地圖" );
	set_short( "魔法地圖" );
	set_long(@CLONG
這是一張魔法地圖，你可以 read map 看地圖內容，或用
read legend 看地圖上符號所代表的意義。
CLONG
	);
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "weight", 5 );
	set( "value", ({ 20, "silver" }) );
}
