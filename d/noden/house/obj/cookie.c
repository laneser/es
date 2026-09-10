// /d/noden/house/obj/cock.c

#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name( "cookie", "小餅乾" );
   set_short("小餅乾");
	set_long(
             "這是一片小小的星形餅乾。\n"
	);
   set("unit", "片");
   set( "weight", 1 );
}
