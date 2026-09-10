#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("black silver plate","黑色銀鎧甲");
        add("id",({"plate","platemail"}) );
         set_short( "a black silver plate ","黑色銀鎧甲");
	set_long(
"This is a suit of plate worn by molader royality ,which can  \n"
"protect your body against opponent's attacks.\n",
"這是一副矮人皇室歷代相傳的鎧甲,可以保護你抵抗敵人的攻擊\n"
	);
	//set("no_sale",1);
	set( "unit", "件" );
	set( "weight", 320 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "fire": 6 ]) );
	set( "value", ({ 450, "gold" }) );
}
