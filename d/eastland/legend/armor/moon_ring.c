#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "moon ring","月戒");
        add( "id", ({"ring"}) );
        set_short("月戒");
        set_long(@C_LONG
一隻因上面鑲有月光寶石而命名的戒指。戒指上閃耀著皎潔無暇的光芒，令人不忍想
玩賞一番。
C_LONG
        );
        set( "unit", "只" );
        set( "type", "finger" );
        set( "material", "element" );
        set( "weight",1);
        set( "defense_bonus", 7 );
        set( "value", ({ 1000, "silver" }) );
}
