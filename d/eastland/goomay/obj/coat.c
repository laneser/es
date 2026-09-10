#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather coat", "皮外套" );
	add( "id", ({ "coat" }) );
	set_short( "a leather coat", "皮外套" );
	set_long(
		"This coat is covered with dirt and has a stink smell.\n",
		"這件皮外套上滿是汙泥與油漬，還有一股濃濃的酒臭味。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
        set("material","leather");
	set( "armor_class", 5 );
	set( "weight", 40 );
	set( "value", ({ 120, "silver" }) );
}
