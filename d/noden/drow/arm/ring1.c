#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper ring", "黃銅指套");
   add( "id", ({ "ring" }) );
        set_short( "黃銅指套" );
        set_long(
@C_LONG
這是個黃銅製的手指套環，上面刻有蜘蛛的標誌。
C_LONG
        );
        set( "unit", "只");
        set( "type", "finger" );
        set( "material", "heavy_metal" );
        set( "defense_bonus", 2 );
        set( "weight", 17 );
        set( "value", ({ 120, "silver" }) );
}
