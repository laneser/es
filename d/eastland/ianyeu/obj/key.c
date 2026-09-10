#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "wooden key", "木鑰匙" );
	add( "id", ({ "key" }) );
   set_short( "木鑰匙" );
	set_long(
            "一把老舊的用烏沉木雕成的鑰匙。\n" );
	set( "unit", "把" );
   set( "to_lock", "IANYEU_LIANG_HOME" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
