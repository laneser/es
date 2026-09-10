#include "../moyada.h"

inherit WEAPON;

void create()
{
	set_name("Controlled Death Scythe", "聽話的死神鐮刀");
	add ("id",({ "scythe", }) );
    set_short("聽話的死神鐮刀");
	set_long(
	    "一把很十分鋒利的大鐮刀，據說是死神心愛的武器。\n"+
	    "它可以用來割草(cropp)嗎? \n"
	);
	set( "unit", "把" );
	set( "weapon_class", 42 );
// set( "type", "shortblade" );
   set( "type", "longblade" );
	set( "min_damage", 25 );
	set( "max_damage", 45 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
    add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
     write( 
       "死神鐮刀苦苦哀求地說: 請不要虐待我。\n"
    );
    return 1;
}
