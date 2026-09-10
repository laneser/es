#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "head", "人頭" );
	set_short( "人頭" );
	set_long(
		"這是一個冒險者的頭。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "個" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
        call_out("disappear",300,this_object());
}

void disappear(object ob)
{
  object owner;
  owner=environment(this_object());
  if (!owner)
    printf("這割下來的人頭因時間而風化掉了。\n"); 
  remove(); 
}
