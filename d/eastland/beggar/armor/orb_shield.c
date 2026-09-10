#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "orb shield", "冰晶盾" );
        add( "id", ({ "shield" }) );
        set_short( "冰晶盾" );
        set_long(@C_LONG
一塊亮晶晶的盾牌。 這是陸阿巧六年前在路上拾獲的一塊千年冰晶研製而成的。當
初為了能煉化這塊冰晶,陸阿巧整整費了七天七夜,再經過三、三,三十六個晝夜才順
利製成的,可謂心血浩大。
C_LONG        
        );
        set("unit","塊");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 7 );
        set( "defense_bonus", 7 );
        set( "weight", 100 );
        set( "value", ({ 4000, "silver" }) );
        set( "light",1);   
}

