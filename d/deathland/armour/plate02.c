#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril full plate","矮人米蘇理鎧甲");
        add("id",({"plate","platemail"}) );
         set_short( "a dwarvern mithril full plate","矮人米蘇理鎧甲");
	set_long(
"This is a suit of full plate made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"這是一副由米蘇理金屬造的鎧甲,可以保護你抵抗敵人的攻擊\n"
	);
	set( "unit", "件" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 32 );
	set( "defense_bonus", 0 );
	set( "value", ({ 220, "gold" }) );
}
