#include "../hole.h"

inherit WEAPON;
void create()
{
	set_name( "Silvery Lance","銀色長槍" );
	add( "id",({ "lance" }) );
	set_short( "銀色長槍" );
	set_long(@LONG
	這是把為蜥蜴人騎士特製的長槍，整把槍是一體
	成形的，完全沒有接縫，重心的位置也恰到好處
	，是把很順手的兵器。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",38 );
	set( "weight",200 );
	set( "value",({ 1370,"silver" }) );
//	set( "no_sale",1 );
}