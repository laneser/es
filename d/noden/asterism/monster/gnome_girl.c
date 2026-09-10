#include "../asterism.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "Gnome little girl", "地精小女孩" );
	add ("id", ({ "girl", "gnome","little girl" }) );
   set_short( "地精小女孩" );
	set_long(
                 "一個地精小女孩.看她好像正專注於研讀手上的書。\n");

    set ("alignment",200 );
    set( "gender", "female" );
    set( "race", "gnome" );
    set( "unit", "個" );
	set_perm_stat( "dex", 6 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(3,1,5);
	set_natural_armor(20,0);
    set ("weight", 200);
    wield_weapon(WEAPONS"small_dagger");
}
