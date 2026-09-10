#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Suntan","軍服" );
	add( "id",({ "suntan" }) );
	set_short( "軍服" );
	set_long(@LONG
	一件卡其色的軍服。
LONG
		);
	set( "unit","件" );
	set( "type","body" );
	set( "material","cloth" );
	set( "armor_class",20 );
	set( "defense_bonus",4 );
	set( "weight",80 );
	set( "value",({ 590,"silver" }) );
}

