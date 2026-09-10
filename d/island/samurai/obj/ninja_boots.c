#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Boots ", "忍者靴 ");
        add( "id", ({ "boots" }) );
        set_short("Ninja Boots", "忍者靴 ");
        set_long(@AAA
一個忍者們穿的防護靴，和其他的鞋子比起來要輕的多，穿上去
你感覺身體好像輕快了一些
AAA
     );
        set( "unit", "件"); 
        set( "type", "feet" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","leather");
        set( "weight", 30 );
        set( "value", ({ 600, "silver" }) );
}
