#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Dragon Scute Tail","龍鱗尾甲" );
	add( "id",({ "tail" }) );
	set_short( "龍鱗尾甲" );
	set_long(@LONG
	這是一套用龍的鱗片打造的尾甲，有高度的防禦力。
LONG
	);
	set( "unit","套" );
	set( "type","tail" );
        set( "material","leather" );
	set( "weight",100 );
	set( "armor_class",10 );
	set( "defense_bonus",3 );
	set( "value",({ 450,"silver" }) );
}