#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Dwarvern mithril ringmail","矮人米蘇理環甲");
        add("id",({"ringmail"}) );
         set_short( "a dwarvern mirhril ringmail","矮人米蘇理環甲");
	set_long(
"This is a suit of ringmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"這是一副由米蘇理金屬造的環甲,可以保護你抵抗敵人的攻擊\n"
	);
	set( "unit", "件" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 87, "gold" }) );
}
