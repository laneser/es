#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron headband", "箍頭鐵界尺");
        add( "id", ({ "headband" }) );
        set_short( "iron headband", "箍頭鐵戒尺");
        set_long(
                "A iron headband for travelling monks .\n",
                "遊方僧侶所戴的護具，因為戴起來不舒服，故可提高注意力\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "monk");
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               (["mental":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 350, "gold" }) );
        set("extra_stats",(["con":-1]));
        set("extra_skills",(["dodge":15]));
}



