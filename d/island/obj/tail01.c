#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Tail","鈦合金尾甲" );
	add( "id", ({ "tail" }) );
	set_short( "鈦合金尾甲" );
	set_long(@LONG
	聖騎士專用的尾甲，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","套" );
	set( "weight",50 );
	set( "type","tail" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 3125,"silver" }) );
}