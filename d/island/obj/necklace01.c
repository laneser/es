#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Sapphire Necklace","藍寶石項鍊" );
	add( "id", ({ "necklace" }) );
	set_short( "藍寶石項鍊" );
	set_long(@LONG
	聖騎士專用的項鍊。還有一個藍寶石墜子，更顯出
	它的高貴。
LONG
           );
	set( "unit","串" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",10 );
	set( "special_defense",([ "fire":10,"electric":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
