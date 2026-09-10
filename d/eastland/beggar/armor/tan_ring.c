#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("tan ring","沖霄雲指");
        add( "id", ({ "ring" }) );
        set_short( "沖霄雲指");
        set_long(@C_LONG
沖霄雲指是陽公公和陰婆婆用千年寒冰製成,看上去還有一閃閃的亮光。
C_LONG
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 5 );
        set( "value", ({ 47, "gold" }) );
}



