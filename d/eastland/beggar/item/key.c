#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "copper key", "銅鑰匙" );
	add( "id", ({ "key" }) );
   set_short( "銅鑰匙" );
   set_long(
            "一把生鏽的銅鑰匙。\n" );
   set( "unit", "把" );
   set( "to_lock", "DBEGGAR_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}
