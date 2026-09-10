#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron chain", "鐵□" );
	add( "id", ({ "chain","whip" }) );
	set_short( "a iron chain", "鐵□" );
	set_long(
		"You see an iron chain which used to lock felonries.\n",
		"這是一條長長的鐵□，是公差們用來追拿犯人的武器。\n"
	);
	set( "unit", "條" );
	set( "weight", 70 );
	setup_weapon( "whip", 15, 8, 16 );
	set( "value", ({ 220, "silver" }) );
        set_c_verbs(({"%s甩向%s","%s砸向%s","%s揮向%s"}));
}
