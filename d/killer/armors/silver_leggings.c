#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蠶絲脛甲";

void create()
{
	set_name( "silver leggings", C_NAME );
	add( "id", ({ "leggings" }) );
	set_short( C_NAME );
	set_long(
		"一副閃亮的銀色脛甲，這副脛甲是諾達尼亞王室的特約工匠麥爾\n"
		"迪藍的精心傑作，他曾經很自豪地向人們說過，這套脛甲的防禦\n"
		"力除了附上魔法以外，已經無法再更強了。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "knight");
	set( "armor_class", 10);
	set( "weight", 150 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
