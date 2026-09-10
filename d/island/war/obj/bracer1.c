#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronz Bracer","青銅護腕" );
	add( "id",({ "bracer" }) );
	set_short( "青銅護腕" );
	set_long(@LONG
	這是一副用青銅打造的護腕，可以確保你再戰
	鬥中不會因為手腕受傷而喪失戰鬥力。
LONG
           );
	set( "unit","副" );
	set( "weight",50 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 450,"silver" }) );
}
