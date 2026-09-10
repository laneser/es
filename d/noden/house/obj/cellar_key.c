#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "cellar key", "酒窖鑰匙" );
	add( "id", ({ "key" }) );
   set_short( "酒窖鑰匙" );
	set_long(
		"一把黃銅做成的鑰匙，上面鉤著一個鐵環。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "GHOST_HAROLD_CELLAR" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
