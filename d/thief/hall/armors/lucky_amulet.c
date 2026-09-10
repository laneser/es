#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "lucky amulet", "幸運護身符" );
	add( "id", ({ "幸運護身符", "amulet" }) );
	set_short( "幸運護身符" );
	set_long(
		"這是個黃金打造的護身符，上面刻滿了各種\n"
		"代表平安、幸運的咒文。\n"
	);
	set( "type", "misc" );
	set( "material", "cloth");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
    set( "special_defense", ([ "mental":5 ]) );
	set( "extra_stats",([ "kar" : 2 ]) );
	set( "weight", 5 );
	set( "value", ({ 1000, "silver" }) );
}
