#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Leather Jackboots","皮革馬靴" );
	add( "id",({ "jackboots","boots" }) );
	set_short( "皮革馬靴" );
	set_long(@LONG
	這是一雙用鹿皮做的長靴，穿起來可是非常舒
	服的喔。
LONG
           );
	set( "unit","雙" );
	set( "weight",50 );
	set( "type","feet" );
	set( "material","leather" );
	set( "armor_class",6 );
	set( "value",({ 450,"silver" }) );
}
