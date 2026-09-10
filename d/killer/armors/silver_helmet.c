#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蠶繭頭盔";

void create()
{
	set_name( "silver helmet", C_NAME );
	add( "id", ({ "helmet" }) );
	set_short( C_NAME );
	set_long(
		"一頂閃亮的銀色頭盔，這頂頭盔是諾達尼亞王室的特約工匠麥爾\n"
		"迪藍的精心傑作，他曾經很自豪地向人們說過，這頂頭盔的防禦\n"
		"力除了附上魔法以外，已經無法再更強了。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "extra_skills", ([ "tactic":10 ]) );
	set( "weight", 70 );
	set( "value", ({ 250, "gold" }) );
	set( "no_sale", 1);
}
