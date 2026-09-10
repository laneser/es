//#pragma save_binary

// translation done. -Elon 03-10-94 left out minor details.
#include "../moyada.h"
#include <money.h>

inherit SHOP;
inherit DOORS;

void create()
{
	::create() ;
	set("light", 1);
	set_short( "商店" );
	set_long( @C_LONG
歡迎來到摩亞達鎮最大也是唯一的商店，這家商店的老闆王虎是遠
從中國西安市來這裡發展，由於原本是個御膳師，所以他煮的菜可說是
遠近馳名。這家商店新開不久，桌椅全是新的，四處整理得一塵不染。
牆上點燃著數把火炬，照亮整個屋子。
C_LONG
);
	set( "exits", ([ 
	  "west" : MOYADA"mainrd1", 
	  "down" : MOYADA"shop/cellar",
	]) );
	
	storeroom()->set("storage", 2);
    storeroom()->set( "objects", ([
        "lamp" : "/obj/lamp",
        "bandage" : "/obj/bandage",
    ]) );
	set( "objects", ([
	    "trashcan" : "/obj/trashcan",
		"Wan Fu"  : MOYADA"monster/wanfu",
		"grey"    : MOYADA"monster/grey",
	]) );
    create_door( "west", "east", ([
	  "keyword" : ({ "wodden door", "door", }),
	  "name"    : "wodden door",
	  "c_name"  : "木門",
	  "c_desc"  : "房子出口的木門",
	  "status"  : "open",
	]) );
	reset();
	replace_program(SHOP);
}
