#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	set_name("moss plaster", "綠苔膏" );
	add( "id", ({"plaster"}) );
	set_short("綠苔膏");
	set_long(
		"這是用來止血用的綠苔膏，將它敷(apply)在傷口上可以止血。\n"
	);
	set( "can_apply", 1 );
	set( "unit", "團" );
	set( "weight", 40 );
	set( "value", ({ 50, "silver" }) );
}

int apply(object player)
{
	if( !player->query("conditions/bleeding") ) return 0;
	BLEEDING->remove_effect(player);
	return 1;
}
