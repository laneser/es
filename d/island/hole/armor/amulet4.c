#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Angel Wing","天使翅膀" );
	add( "id", ({ "wing" }) );
	set_short( "天使翅膀" );
	set_long(@LONG
	可發揮神聖力量的天使翅膀，天使會透過這翅
	膀傳送力量。
LONG
		);
	set( "unit","對" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "evil":20,"fire":20 ]) );
	set( "value",({ 1900,"silver" }) );
}
