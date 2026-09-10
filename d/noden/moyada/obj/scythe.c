#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Scythe", "鐮刀");
	add ("id",({ "scythe", }) );
	set_short("鐮刀");
	set_long(
	    "一把很鋒利的鐮刀，可用來割草(cropp)。\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 5 );
	set( "type", "shortblade" );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "weight", 35 );
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
        object obj1, obj2;
        
        if ( !str || str=="" )
          write("你要割什麼 ?\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2=environment(obj1);
            if ((int)obj2->query("cropp")==1) 
              obj2->to_find_cropp(str);
            else write("你不能割它！\n");
          }
          else return notify_fail("你手上並沒有工具。\n");  
        }
        return 1;
}
