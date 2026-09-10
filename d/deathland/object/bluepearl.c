#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "blue pearl", "藍珍珠" );
	add( "id", ({ "pearl" }) );
	set_short( " blue pearl", "藍珍珠" );
	set_long(
		"The very expensive pearl,but you think nobody can understand its value\n",
		"非常昂貴的珍珠,但是你想大概沒有人能瞭解它的價值\n"
	);
	set( "no_sale", 1 );
	set( "unit", "個" );
	set( "echo_pearl",1);
	set( "weight", 13 );
	set( "value", ({ 1, "silver" }) );
}
