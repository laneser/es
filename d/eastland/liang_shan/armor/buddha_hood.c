#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("buddha hood", "麻羅□字頂巾");
        add( "id", ({ "hood" }) );
        set_short( "buddha hood", "麻羅□字頂巾");
        set_long(
                "A hood with a buddha mark .\n",
                "這是一頂麻紗巾，上有一個紅色的□字，據說可以壓制體內瘋狂的 \n"
                "獸性．所以宋江特地將它賞給李逵．\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":7,"mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 300, "gold" }) );
}


