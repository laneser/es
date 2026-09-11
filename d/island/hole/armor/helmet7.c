#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Holy helm","聖冠" );
	add( "id", ({ "helm","helmet" }) );
	set_short( "聖冠" );
	set_long(@LONG
	雕刻歷代聖者之名的頭冠，戴在頭上可以受到
	聖者的保護。
LONG
		);
	set( "unit","頂" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","light_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 3650,"silver" }) );
}
