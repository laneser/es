#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fan", "蒲扇" );
	set_short( "蒲扇" );
	set_long(@LONG
一面造型輕巧的花扇，上繡著翩翩飛舞的蝴□。
LONG
	);
	set( "unit","面");
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 15 );
	set( "max_damage", 22 );
	set( "weight", 50 );
}
