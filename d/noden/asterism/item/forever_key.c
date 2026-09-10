#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "key of forever", "永恆之鑰" );
	add( "id", ({ "key" }) );
   set_short( "永恆之鑰" );
	set_long(
		"一把閃耀著奇異光芒的三角形黑曜石鑰匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "ASTERISM_2" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
        
}

void init()
{
   
}


  
