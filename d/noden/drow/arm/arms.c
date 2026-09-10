#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake armbands", "蛇護臂");
   add( "id", ({ "armbands" }) );
        set_short( "蛇護臂" );
        set_long(
@C_LONG
這是一個由蛇皮纏捲成的護臂，邊緣還用銅片交織緊密地結合。
C_LONG
        );
        set( "unit", "對");
        set( "type", "arms" );
        set( "material", "leather" );
   set( "armor_class", 3 );
   set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "poison": 18, "cold": -5 ]) );
        set( "weight", 32 );
        set( "value", ({ 110, "gold" }) );
        set( "no_sale", 1);
}
