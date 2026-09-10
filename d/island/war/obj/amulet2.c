#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Amulet","白金徽章" );
	add( "id", ({ "amulet" }) );
	set_short( "白金徽章" );
	set_long(@LONG
	古代階級的徽章之一，就體制流傳下來的寶物
	，至今仍俱有高貴的價值。
LONG
           );
	set( "unit","枚" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",4 );
	set( "value",({ 2620,"silver" }) );
}
