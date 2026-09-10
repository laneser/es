#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("copper blunt","銅杖");
   add("id",({"blunt"}));
   set_short("銅杖");
       set_long(
@C_LONG
　　這是把銅製的長柄柺杖，在杖頭上雕刻有蜘蛛的圖紋。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 11 );
        set("type","blunt");
        set( "min_damage", 12 );
        set( "max_damage", 16 );
        set( "weight", 50 );
        set( "value", ({ 180 , "silver" }) );
}
