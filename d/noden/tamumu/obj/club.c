#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "club", "狼牙棒" );
	add( "id", ({ "spiked club" }) );
	set_short( "狼牙棒" );
	set_long(
   "這根狼牙棒上面有許多尖尖的鐵刺，看起來是件沈重的戰士級武器。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 7 );
	set( "max_damage", 24 );
	set( "weight", 170 );
	set( "value", ({ 230, "silver" }) );
}
