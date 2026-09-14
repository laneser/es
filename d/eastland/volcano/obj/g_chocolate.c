#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "gold_chocolate", "金色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short( "gold_chocolate", "金色巧克力" );
	set_long(
		"這是一個包著甜酒的巧克力，你可以嚐嚐看(taste)。\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   if(!arg || arg!="chocolate")
   { write("你要吃什麼？\n");
     return 1;
   };

   write("你吃了一塊包著酒的巧克力，它慢慢的化在嘴裡，甜酒也跟著慢慢的流出。\n");
   write("你感到說不出的舒服，真想再吃一塊。\n");
   this_player()->receive_healing(5);
   this_object()->remove();
   return 1;
}
