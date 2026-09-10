#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "puty seed", "如意菩提子" );
	add( "id", ({ "seed" }) );
	set_short( "如意菩提子" );
	set_long(@C_LONG
這是一顆千年菩提子，它吸收日月精華並受佛祖祝福過, 
服用它可以恢復大量體力。
C_LONG
	);
	set_healing( 120 );
	set( "no_sale", 1 );
	set( "weight", 8 );
	set( "value", ({ 10, "gold" }) );
}
