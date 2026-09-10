#include "../echobomber.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Pick", "十字鎬");
	add ("id",({ "pick" }) );
	set_short("a dwarven pick", "矮人的十字鎬");
	set_long(
            "一把矮人的十字鎬，可用來開鑿(excavate)\或是挖掘(dig)。\n"
	);
	set( "unit", "只" );
	set( "weapon_class", 7 );
	set( "type", "thrusting" );
	set( "min_damage", 5 );
	set( "max_damage", 18 );
	set( "weight", 120 );
	set( "value", ({ 460, "silver" }) );
}

void init()
{
        add_action("to_excavate","excavate");
        add_action("to_excavate","dig");
}

int to_excavate(string str)
{
        object obj1, obj2;
        
          if ( !str || str=="" )
           return notify_fail("你想挖什麼東西?\n"); 
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if (!( obj2->query("direction") )) 
               return notify_fail("破壞環境是不好的行為.\n");
            
            if ((string)obj2->query("direction")=="block" ) 
              obj2->to_find_excavate(str);
             // write ("當你試著挖掘時,一隻可怕的怪獸向你衝來,\n");
            else
              return notify_fail( 
                "由於這裡是矮人的地盤,你不能在這裡開鑿！\n");
            }
          else return notify_fail( 
            "你手上並沒有工具。\n");  
        return 1;
}
