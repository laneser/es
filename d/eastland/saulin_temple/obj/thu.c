#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
    set_name("king-kong thu","金剛杵");
    add("id",({"mace","thu"}) );
    set_short("金鋼杵");
    set_long(
		"由金剛砂和黑銀混合製成的金剛杵, 相傳是大力金剛用來降魔伏妖的法器。\n"
    );
	set( "unit", "把" );
 	set( "weapon_class", 37 );
	set("type","bo");
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "weight", 230 );
        set( "nosecond",1); 
	set( "value", ({ 200, "gold" }) );
}
