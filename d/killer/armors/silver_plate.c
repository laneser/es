#include <mudlib.h>

inherit ARMOR;

string C_NAME="天蠶繭盔甲";

void create()
{
	set_name( "silver platemail", C_NAME );
	add( "id", ({ "plate", "platemail" }) );
	set_short( C_NAME );
	set_long(
		"一套閃亮的銀色盔甲，這套盔甲是諾達尼亞王室的特約工匠麥爾\n"
		"迪藍的精心傑作，他曾經很自豪地向人們說過，這套盔甲的防禦\n"
		"力除了附上魔法以外，已經無法再更強了。\n"
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "knight");
	set( "armor_class", 40 );
	set( "weight", 370 );
	set( "value", ({ 330, "gold" }) );
	set( "no_sale",1 );
}
