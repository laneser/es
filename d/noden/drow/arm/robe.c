#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake skin robe", "蹂蛇皮長袍");
   add( "id", ({ "robe" }) );
        set_short( "蹂蛇皮長袍" );
        set_long(
@C_LONG
這是一件已經過處理的軟皮革的長袍，能有效地覆蓋住你的身體並
且避免傷害，是黑暗精靈手工藝的代表作。
C_LONG
        );
        set( "unit", "件");
        set( "type", "body" );
        set( "material", "leather" );
        set( "armor_class", 14 );
   set( "defense_bonus", 8 );
        set( "special_defense",
               ([ "poison":6 ]) );
        set( "weight", 130 );
        set( "value", ({ 1000, "silver" }) );
}
