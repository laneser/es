#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name( "shield of Alaits", "阿萊特斯之盾");
        add( "id", ({ "shield" }) );
        set_short( "阿萊特斯之盾");
        set_long(
           "矮人皇室阿萊斯特家族傳家的盾牌,盾上還刻了兩隻雄壯的獅鷲獸。\n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 10 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set("special_defense",
              (["evil":10,"fire":10,"cold":10]) );
        set( "value", ({ 250, "gold" }) );
        
}






