#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Dragon Knight's Lance","龍騎士槍" );
	add( "id",({ "jousting","lance" }) );
	set_short( "龍騎士槍" );
	set_long(@LONG
	龍騎士騎馬時所用的槍，徙步時亦可發揮強大
	威力。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",50 );
	set( "min_damage",25 );
	set( "max_damage",60 );
//	set( "bleeding",20 );
	set( "weight",200 );
	set( "value",({ 13500,"silver" }) );
//	set( "no_sale",1 );
	set( "nosecond",1 );
	set( "prevent_insert",1 );
}