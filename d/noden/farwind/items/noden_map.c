#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
         seteuid(getuid());
	set_name( "map", "地圖" );
	set_short( "諾頓王國地圖" );
	set_long(@CLONG
這是諾頓王國的全圖，你可以 read map 看地圖內容，或用
read legend 看地圖上符號所代表的意義。
CLONG
	);
	set_size( 21, 21 );
	set( "prevent_get", 1 );
	set_center_coordinate( 10, 10, "/d/noden/virtual/noden_server");
}
