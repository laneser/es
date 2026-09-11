#include "../hole.h"

inherit WEAPON;
void create()
{
	set_name( "Ebony Lance","黑檀木柄長槍" );
	add( "id",({ "lance" }) );
	set_short( "黑檀木柄長槍" );
	set_long(@LONG
	這是蜥蜴人禁衛軍專用的長槍，握柄的部份是用
	黑檀木做的，可以算的上是一種高級品。
LONG
		);
	set( "unit","把" );
	set( "type","jousting" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",140 );
	set( "value",({ 2330,"silver" }) );
}