#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Black Spear","黑色長矛" );
	add( "id",({ "spear" }) );
	set_short( "黑色長矛" );
	set_long(@LONG
	這是把普通的長矛，雖不是神兵利器，但是足
	以用來防身。
LONG
	);
	set( "unit","把" );
	set( "type","thrusting" );
	set( "weapon_class",28 );
	set( "min_damage",20 );
	set( "max_damage",30 );
	set( "weight",200 );
	set( "value",({ 1000,"silver" }) );
}