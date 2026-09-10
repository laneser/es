#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "patrick", "派區克" );
	add( "id", ({ "captain" }) );
   set_short( "派區克船長" );
	set_long(
		"派區克船長剛剛為了還賭債，把他的船賣掉了，一個人在這裡喝悶酒。\n"
		"如果你識相的話，不要在他面前提起「船(ship)」這個字。\n"
	);
	set( "race", "lizardman" );
	set( "gender", "male" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 13 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );

	set( "tactic", "assault" );
	set( "wealth/gold", 25 );
	set( "inquiry", ([
		"ship" : "@@ask_ship"
	]) );

	wield_weapon( "/d/noden/bluesand/item/long_cutlass" );
	equip_armor( "/d/noden/bluesand/item/eye_patch" );
	equip_armor( "/d/noden/bluesand/item/boots" );
}


void ask_ship(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
                 "派區克船長怒吼道: 連你也敢取笑我？等我解決了這小子再找你算帳！\n",
			this_object() );
	} else {
            tell_room( environment(),
                    "派區克船長臉上一陣青一陣白，大喝: 臭小子！你不要命了？\n",
			this_object() );
		kill_ob( player );
	}
}
