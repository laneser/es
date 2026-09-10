#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper plate", "青銅鎧甲" );
        add( "id", ({ "plate" }) );
        set_short( "青銅鎧甲");
        set_long(
@C_LONG
這是由青銅所打造的厚重鎧甲，在鎧甲的表面並且印上蜘蛛的記號
，這是黑暗精靈武士所喜愛的防具，能有效的保護身體免受敵人的
攻擊。
C_LONG
        );
        set( "unit", "件");
        set( "type", "body" );
        set( "material", "heavy_metal" );
        set( "armor_class", 16 );
        set( "defense_bonus", 4 );
        set( "special_defense",
        ([ "fire" : 12, "cold" : -8 ]) );
        set( "weight", 200 );
        set( "value", ({ 970, "silver" }) );
}
