#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Sapphire Ring","藍寶石戒指" );
	add( "id", ({ "ring" }) );
	set_short( "藍寶石戒指" );
	set_long(@LONG
	聖騎士專用的戒指。上面還鑲著一個藍寶石，更顯出
	它的高貴。
LONG
           );
	set( "unit","只" );
	set( "weight",5 );
	set( "type","finger" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "soecial_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
