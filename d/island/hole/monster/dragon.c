#include <mudlib.h>
#include <races.h>

inherit RACE_DRAGON;
inherit MOUNT;

void create()
{
	::create();
	set_level(17);
	set_name( "Fire Dragon","火龍" );
	add( "id", ({ "dragon" }) );
	set_short( "火龍" );
	set_long(@LONG
這是一頭噴火巨龍，聽說只要能馴服它便可以將他變成坐騎。
LONG
		);
	set( "unit","頭" );
	set( "race","dragon" );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",15 );
	set_natural_weapon( 45,40,60 );
	set_natural_armor( 80,40 );
	set( "alignment",300 );
	set( "extra_look","$N正騎著一頭巨大的火龍，看起來猶如天神一般。\n" );
//	set( "mountable",1 );
	set( "max_load", 2600 );
}

void init()
{
	mount::init();
}
