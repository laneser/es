#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("gold necklace","玉墜項鍊");
        add("id",({"gold","necklace",}) );
         set_short( "a gold necklace","玉墜項鍊");
	set_long(
"This is a gold necklace \n"
"這是一個由金子打造的項鍊，鍊上有個古玉墜子，看起來非常美麗。\n" 
	);
	set( "unit", "串" );
	set( "weight", 12 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 160, "gold" }) );
}
