#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "water ring", "神水戒" );
	add( "id", ({ "ring" }) );
	set_short( "神水戒" );
	set_long( 
@C_LONG
水之護衛所戴的戒指，湛藍地如同大海一樣深邃。
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 4 );
	set( "special_defense", 
	     ([ "cold":5, "fire":-10 ]) );
	set( "extra_skills", ([ "inner-force":10 ]) );
	set( "extra_stats", ([ "dex":-1 ]) );      
	set( "weight", 5 );
	set( "value", ({ 1900, "silver" }) );
}
