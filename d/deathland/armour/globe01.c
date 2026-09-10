#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("beholder globe","眼魔護盾圓球");
        add("id",({"globe"}) );
         set_short( "a beholder globe","眼魔護盾圓球");
	set_long(
"一個球狀的反物質,像是一種護盾產生器\n"
	);
	set( "echo_chain_need",1);
	set( "unit", "種" );
	set( "weight", 110 );
	set( "type", "globe" );
	set( "material", "element" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "fire":5, "cold":5, "electric":5, "energy":5, "divine":-20 ]) ); 
	set( "value", ({ 48, "gold" }) );
 //        set( "no_sale", 1 );
}
