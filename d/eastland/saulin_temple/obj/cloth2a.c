#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("zu-lai plate","如來甲冑");
    add("id",({"zu-lai","plate"}) );
    set_short("如來甲冑");
	set_long(
	"這是金剛界大曼荼羅北方羯磨部第二金剛護的甲冑,又稱如來甲冑。\n" 
	);
	set( "unit", "件" );
	set( "weight", 150 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 230, "gold" }) );
}
