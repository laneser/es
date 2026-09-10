
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("fish-scale suit","魚皮戰甲");
        add("id",({"suit"}) );
         set_short("魚皮戰甲");
        set_long(
"這是一套由特殊處理過的魚皮製成的緊身戰甲，有良好的防禦力。\n"
        );
        set( "unit", "套" );
        set( "weight", 220 );
        set( "type", "body" );
        set( "material", "leather" );
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
        set( "value", ({ 87, "gold" }) );
}
