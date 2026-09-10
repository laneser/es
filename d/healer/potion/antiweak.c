#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("strong pill", "養生主" );
	add( "id", ({"pill"}) );
	set_short("養生主");
	set_long(
		"這是由刑老爹研發出來的補藥,對身體虛弱的人有很好的療效。\n"
		"如果你覺得力不從心,吃(eat)下它保證讓你四十歲還像一尾活龍!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
        set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/weak") ) return;
	tell_object( player, can_read_chinese(player)?
		"你覺得全身又充滿精力！\n": "You recover from poison!\n" );
	stat = (int) player->query("weak");
	player->modify_stat("str",stat);	
	"/std/conditions/weak"->remove_effect(player);
}
