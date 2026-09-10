#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "diamond ring", "鑽石戒指" );
	add( "id", ({ "ring","diamond"}) );
	set_short( "diamond ring", "鑽石戒指" );
	set_long(@C_LONG
一隻泛出光芒耀眼的鑽石戒指．看起來很貴的樣子．
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
        set( "material", "element");
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "magic":5 ]) );      
	set( "weight", 5 );
	set( "value", ({ 6000, "silver" }) );
}
