#include "../../layuter.h"
inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Silver Shovel", "銀鏟子");
	add ("id",({ "shovel" }) );
	set_short("銀鏟子");
	set_long(
            "一把銀鏟子，可用來挖崛(dig)。\n"
	);
	set( "weapon_class", 10 );
	set( "type", "blunt" );
	set( "min_damage", 1 );
	set( "max_damage", 2 );
	set( "weight", 20 );
	set( "value", ({ 50, "silver" }) );
	set( "unit", "把" );
}

void init()
{
        add_action("to_dig","dig");
}

int to_dig(string str)

{
        object obj1, obj2,ob3;
        
        if ( !str || str!="north" )
          write("Dig what ?\n");
        else {
          obj1=environment(this_object());
          if (obj1==this_player()) {
            obj2 = environment(obj1);
            if (((int)obj2->query("layuter_dig")==1)&&((int)obj2->query("beer_control")==1)) 
              {
               obj2->set("beer_control",0);
               write("你挖到一瓶陳年女兒紅\n");
                  ob3=new(Lditem"beer");
                  ob3->move(obj2);
              }
            else
              write("你在這裡挖了很久，可是挖不到任何東西！\n");
          }
          else return notify_fail("你手上並沒有工具。\n");  
        }
        return 1;
}
