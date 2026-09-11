#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( " Ring","烙印戒指" );
	add( "id", ({ "ring" }) );
	set_short( "烙印戒指" );
	set_long(@LONG
	刻著惡魔徽章的戒指。可用它將罪烙印在別人
	身上，而得惡魔的保護。
LONG
           );
	set( "unit","只" );
	set( "weight",5 );
	set( "type","finger" );
	set( "material","element" );
	set( "defense_bonus",7 );
	set( "special_defense",([ "evil":20,"devine":-15 ]) );
	set( "value",({ 2440,"silver" }) );
}
