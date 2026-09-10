#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Armbands","白金護臂" );
	add( "id", ({ "arm","armband" }) );
	set_short( "白金護臂" );
	set_long(@LONG
	一對用白金打造的護臂。
LONG
           );
	set( "unit","對" );
	set( "weight",9 );
	set( "type","arms" );
	set( "material","knight" );
	set( "armor_class",3 );
	set( "defense_bonus",2 );
	set( "value",({ 1175,"silver" }) );
}
