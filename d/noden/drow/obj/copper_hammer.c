#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("copper hammer","銅角槌");
   add("id",({"hammer"}));
   set_short("銅角槌");
       set_long(
@C_LONG
這是把由銅片鑲在原木塊上的槌子，握把的地方刻有蜘蛛的圖案。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 15 );
        set("type","blunt");
        set( "min_damage", 14 );
        set( "max_damage", 20 );
        set( "weight", 80 );
        set( "value", ({ 280 , "silver" }) );
}
