
#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蠶繭盾";

void create()
{
	set_name( "silver shield", C_NAME );
	add( "id", ({ "shield" }) );
	set_short( C_NAME );
	set_long(
		"一面閃亮的銀色盾牌，這面盾牌是諾達尼亞王室的特約工匠麥爾\n"
		"迪藍的精心傑作，他曾經很自豪地向人們說過，這面盾牌的防禦\n"
		"力除了附上魔法以外，已經無法再更強了。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material" ,"knight");
	set( "armor_class", 10 );
	set( "extra_skills", ([ "block":10 ]) );
	set( "weight", 100 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
