#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "bone blade", "骨刀" );
        set_short( "骨刀" );
        add ("id", ({ "blade",}) );
	set_long(@C_LONG
骨刀是採取動物身上骨骼部份所做成的, 雖然如此, 但還是很尖銳的。
C_LONG	
	);
	set( "unit", "把" );
	set( "weight", 100 );
	setup_weapon("longblade",15,13,18);
        set( "value", ({ 400, "silver" }) );
}

