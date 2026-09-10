#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Ebony Sword", "焦殤劍" );
	add( "id", ({ "sword" }) );
	set_short( "Ebony Sword", "焦殤劍" );
	set_long(
		"You see a black longsword with a smell of burning spices.\n",
		"這是一把通體呈墨黑色的劍，你把劍刃向著亮光處一照，竟是半點\n"
		"光澤也沒有，仍是墨色一片。你隱約可以嗅到劍身散發出一股燒艾\n"
		"草的焦味。\n"
	);
	set( "unit", "把" );
	set( "weight", 60 );
	setup_weapon( "longblade", 30, 24, 30 );
	set( "bleeding", 10 );
	set( "value", ({ 365, "gold" }) );
	set( "no_sale", 1 );
}
