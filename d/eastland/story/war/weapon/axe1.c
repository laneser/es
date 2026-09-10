#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "large axe", "巨斧" );
    add( "id", ({ "axe" }) );
    set_short( "巨斧" );
    set_long(@LONG
一柄沈重的斧頭，前鋒相當銳利。
LONG
    );
    set( "unit", "柄" ); 
    set( "weight", 150 ); 
    set( "value", ({ 1800,"silver" }) ); 
    set( "bleeding",5); 
    setup_weapon("axe", 33,23,38);
}
