#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's amulet", "巫師護身符" );
	add( "id", ({ "amulet" }) );
	set_short( "a wizard's amulet", "巫師護身符" );
	set_long(
		"This is Rashudi's magical amulet. You can see many symbols\n"
		"of magical shield on it.\n",
		"這個護身符是拉修帝最常帶在身邊的，上面畫滿了各種魔法防禦的咒文。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 10 );
	set( "special_defense",
	     ([ "fire":10, "cold":10, "electric":5, "energy":5 ]) );
	set( "extra_skills", ([ "meditate":10 ]) );     
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 5500, "silver" }) );
}
