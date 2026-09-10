
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("ice demon's amulet","陰魔符");
        add("id",({"amulet"}) );
         set_short("陰魔符");
        set_long(
"這是一個白色的護身符，但是上面卻濺滿了斑斑血跡，顯得很詭異。\n"
        );
        set( "no_sale",1);
        set( "unit", "個" );
        set( "weight", 10 );
        set( "type", "misc" );
        set( "material", "element" );
        set( "armor_class", 0 );
	set( "defense_bonus", 5 );
        set( "special_defense", ([ "ice":8, "fire":-10 ]) );
        set( "value", ({ 88, "gold" }) );
}
