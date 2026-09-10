#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "murasame blade", "妖刀" );
	add( "id", ({ "murasame", "blade" }) );
   set_short( "妖刀村正" );
	set_long(
		"在你面前這把正散發著陰森森寒氣的長刀就是惡名昭彰的「妖刀村正」，它\n"
		"正散發出一股妖氣吸引著你拿它去殺死敵人。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 90 );
   set( "weapon_class", 45 );
   set( "min_damage", 18 );
	set( "max_damage", 47 );
   set( "bleeding", 20 );
	set( "value", ({ 700, "silver" }) );
// set( "extra_stats", ([ "kar" : -7 ]) );
}
