#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper armbands", "黃銅臂環");
   add( "id", ({ "armbands" }) );
        set_short( "黃銅臂環" );
        set_long(
@C_LONG
這是由黃銅打造的臂環，厚重而結實的材質能保護你的手臂。
C_LONG
        );
        set( "unit", "對");
         set( "type","arms" );
        set( "material", "heavy_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "weight", 65 );
        set( "value", ({ 210, "silver" }) );
}
