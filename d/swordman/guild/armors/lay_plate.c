#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1m破神甲[37;0m";

void create()
{
	set_name( "The plate of antilordus", C_NAME );
	add( "id", ({ "plate", "platemail" }) );
	set_short( C_NAME );
	set_long(@LONG
這是一套閃閃發亮的戰袍，傳說是屠龍道人斬殺了長河惡蛟後
剝了它的皮製成的。一片片閃著輝光的鱗甲層層疊疊的覆滿整套盔
甲，不僅能夠提供嚴密的保護，更不會妨礙行動。
LONG
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "swordman");
	set( "armor_class", 32 );
	set( "defense_bonus",4);
	set( "weight", 200 );
	set( "value", ({ 30, "gold" }) );
	set( "no_sale",1 );
}
