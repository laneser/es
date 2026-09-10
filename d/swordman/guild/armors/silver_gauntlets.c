#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1m銀手套[37;0m";

void create()
{
	set_name( "silver gauntlets", C_NAME );
	add( "id", ({ "gauntlets" }) );
	set_short( C_NAME );
	set_long(
		"一雙閃亮的銀色手套，這雙手套是諾達尼亞王室的特約工匠麥爾\n"
		"迪藍的精心傑作，他曾經很自豪地向人們說過，這雙手套的防禦\n"
		"力除了附上魔法以外，已經無法再更強了。\n"
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "knight" );
	set( "armor_class", 5 );
	set( "extra_skills", ([ "parry" :10 ]) );
	set( "weight", 80 );
	set( "value", ({ 210, "gold" }) );
	set( "no_sale", 1);
}
