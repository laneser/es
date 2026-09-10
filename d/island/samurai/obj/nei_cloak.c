#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Cloak", "雷電披風");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "雷電披風");
        set_long(@AAA
這是一件附有雷電精靈力量的披風
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["eletric":7]));
        set( "weight", 30 );
        set( "value", ({ 700, "silver" }) );
}
