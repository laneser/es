#include "../oldcat.h"

inherit OBJECT;

void init()
{
	add_action( "hold_ball", "hold" );
}

void create()
{
        set_name( "prevent_water ball", "闢水珠" );
        add( "id", ({ "ball" }) );
        set_short( "闢水珠" );
        set_long(
@LONG
一顆用獨角獸的角磨製的闢水珠，據說只要手握著它，就可將水分出一條路來。
LONG
		);
   		set("unit","顆");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
                set("no_sale", 1 );
}

int hold_ball(string arg)
{
    if( !arg || arg != "ball" ) return 0;
    if ((int)environment(this_player())->query("in_well")==1 ) {
    	tell_object(this_player(),
    	    "你手握闢水珠，只見眼前的水自動分出一條路來。\n");
        this_player()->set_temp("likefish",1);
    } else
        tell_object(this_player(), 
             "你手握闢水珠，，但是不是用錯地方了呢。\n" );
    return 1;

}
