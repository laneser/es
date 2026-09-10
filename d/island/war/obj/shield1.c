#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Shield","青銅盾" );
	add( "id", ({ "shield" }) );
	set_short( "青銅盾" );
	set_long(@LONG
	這是一面用青銅打造的盾，在盾的邊緣還鑲有
	一些藍寶石，這類型的盾是蜥蜴人騎士的標準
	配備。
LONG
           );
	set( "unit","面" );
	set( "weight",150 );
	set( "type","shield" );
	set( "material","knight" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "value",({ 1260,"silver" }) );
}
