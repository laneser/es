#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "visitor", "觀光客" );
	set_short( "觀光客" );
	set_long(
		"他是一個初到本鎮的觀光客，正在對著新奇的事物指指點點。\n"
	);
        set ("gender", "male");
        set ("race", "human");
        set("unit","個");
        set_natural_armor( 28, 10 );
        set_natural_weapon( 6, 5, 13 );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 12 );
	set_skill( "dodge", 60 );
	set( "chat_chance", 15 );
	set( "att_chat_output", ({
		"觀光客哭著道：「強盜先生，我什麼都給你 !! 不要殺我 !!」。\n",
	}) );
        set ("wealth", ([ "silver": 50 ]) );
        equip_armor( Obj"glasses" );
}
