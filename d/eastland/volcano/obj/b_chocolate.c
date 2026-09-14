#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "blue_chocolate", "藍色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short(  "藍色巧克力" );
	set_long(
		"這是一個包著神秘禮物的巧克力，你可以嚐嚐看(taste)。\n"
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
   int fp,maxfp;

   if(!arg || arg!="chocolate")
   { write("你要吃什麼？\n");
     return 1;
   };

   write("你吃了這塊巧克力，嚇!竟然一隻雞腿藏在裡面。\n");
   write("你吃了之後發現肚子咕嚕咕嚕直叫，看來不跑廁所不行了。\n");
   maxfp=this_player()->query("max_fp");
   fp=this_player()->query("force_points");
   if (maxfp<(fp+10))
     this_player()->set("force_points",maxfp);
   else
     this_player()->set("force_points",fp+5);
   this_object()->remove();
   return 1;
}
