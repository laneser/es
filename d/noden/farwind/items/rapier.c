#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "light rapier", "輕型劍" );
	add( "id", ({ "rapier" }) );
	set_short( "輕型劍" );
	set_long(@CLONG
這是一種普通劍士十分喜愛的劍，劍身細長而且易於揮動，劍柄
部份還有金屬的護手凹槽。
CLONG
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 12 );
	set( "weight", 60 );
	set( "value", ({ 240, "silver" }) );
}
