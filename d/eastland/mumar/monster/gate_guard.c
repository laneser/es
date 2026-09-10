#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "gate guard", "城門守衛" );
	add( "id", ({ "guard" }) );
        set_short("城門守衛");
	set_long(
		"這個城門守衛是個典型的彪型大漢，站在你面前像座鐵塔一般，他的任務\n"
		"是守衛牧馬關的城門。\n"
	);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 80 );
	set_skill( "block", 80 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 600 );
	set_natural_armor( 80, 20 );
	set_natural_weapon( 5, 10, 10 );

	wield_weapon( "/d/eastland/mumar/obj/glaive" );
	equip_armor( "/d/eastland/mumar/obj/shield" );
}
