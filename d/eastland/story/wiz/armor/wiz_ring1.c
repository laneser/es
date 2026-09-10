#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's ring","護國師□戒");
        add( "id", ({ "ring" }) );
        set_short( "護國師□戒");
        set_long(@C_LONG
一隻晶瑩剔透不時閃耀著五彩祥雲的戒指。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 1 );
        set( "value", ({ 1500, "silver" }) );
        set("special_defense",
             (["magic":30,"divine":-60]) );
}



