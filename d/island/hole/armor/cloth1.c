#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Phenix Robe","鳳凰長袍" );
	add( "id",({ "robe" }) );
	set_short( "鳳凰長袍" );
	set_long(@LONG
	由不死神獸鳳凰的翅膀所編織的長袍。
LONG
           );
	set( "unit","件" );
	set( "weight",50 );
	set( "type","body" );
	set( "material","leather" );
	set( "armor_class",28 );
	set( "defense_bonus",8 );
	set( "special_defense",([ "fire":30,"evil":20 ]) );
	set( "value",({ 5720,"silver" }) );
}