#include "../almuhara.h"

inherit ARMOR;

void create()
{
        set_name("Holy helmet", "伏魔聖盔");
        add( "id", ({ "helmet" }) );
        set_short( "伏魔聖盔");
        set_long(
        "這是用某種奇異金屬所製成的頭盔，可以保護你免於邪惡敵人的攻擊。 \n"
                
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense", ([ "evil" : 5 ]) );
        set( "weight", 60 );
        set( "value", ({ 1800, "silver" }) );
}



