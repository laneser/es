#include <mudlib.h>
#include <move.h>
inherit OBJECT;

void create()     
{
#include <compress_obj.h>
	set_name( "light ball", "光球" );
	set_short( "發光的球");
	set_long( @LONG
這光球是由發光粒子集合而成, 它散發出淡淡的光芒, 讓你可以看清四周的景物。
LONG
    );
	set("id", ({ "ball" }));
	set("unit", "顆");
	set("weight", 0);
	set("light", 1);
	set("no_insert", 1);
	set("useless", 1);
	set("prevent_insert",1);
	set("value", ({ 1, "silver" }));
}

void set_fuel(int fuel)
{
    call_out( "burn_out", fuel, this_object() );
}

void burn_out(object obj)
{
	object owner;

	owner = environment(obj);
	if( living(owner) ) {
	  tell_object( owner,"你的光球閃了幾下，消失了。\n");
	  tell_room( environment( owner ), 
	    owner->query("c_name")+"的光球閃了幾下，消失了。\n" ,
	    owner
	  );
	}
    obj->remove();
}

int move( mixed place )
{    
    if( objectp(place) && !living(place) )
      call_out( "disappear", 2, this_object() );
    return ::move(place);
}

void disappear( object obj )
{
    tell_room( environment(obj), 
      "光球閃了幾下，消失了。\n" , obj
    );
    obj->remove();
}
