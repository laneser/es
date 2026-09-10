#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Bracer","銀色護腕" );
	add( "id",({ "bracer" }) );
	set_short( "銀色護腕" );
	set_long(@LONG
	這是一副閃耀著銀色光芒的護腕。
LONG
           	);
	set( "unit","副" );
	set( "weight",45 );
	set( "type","hands" );
	set( "material","light_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 470,"silver" }) );
}
