#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron hat", "渾鐵打就四方鐵帽");
        add( "id", ({ "hat" }) );
        set_short( "iron hat", "渾鐵打就四方鐵帽");
        set_long(
                "A iron helmet .\n",
                "這是用鑌鐵鑄成的方帽，如果再黑一點就很像畢業典禮用的那種． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":5 ]) );
        set( "weight", 65 );
        set( "value", ({ 100, "gold" }) );
}



