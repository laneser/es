#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Ironsteel chainmail","鐵鋼鎧甲");
        add("id",({"chainmail"}) );
         set_short( "a ironsteel chainmail","鐵鋼鎧甲");
	set_long(
"This is a suit of chainmail made of iron steel,which can  \n"
"protect your body against opponent's attacks.\n",
"這是一副由鐵鋼造的鎧甲,可以保護你抵抗敵人的攻擊\n"
	);
	set( "unit", "件" );
	set( "weight", 300 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 22 );
	set( "defense_bonus", 0 );
	set( "value", ({ 1470, "silver" }) );
}
