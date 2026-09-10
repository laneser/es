#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("spirit pill","醒腦丸" );
	add( "id", ({"pill"}) );
	set_short("醒腦丸");
	set_long(
		"這是一份行醫者所調配的醒腦丸，吃(eat)下它可以解除混亂的\n"
		"狀態。\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 10 );
	set( "value", ({ 30, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
	if( !player->query("conditions/confused") ) return;
//      tell_object( player,
//             "你所覺的腦子清醒多了 !\n");
	CONFUSED->remove_effect(player);
}
