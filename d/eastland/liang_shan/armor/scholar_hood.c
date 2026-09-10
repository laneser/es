#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("scholar hood", "綸巾");
        add( "id", ({ "hood" }) );
        set_short("綸巾");
        set_long(
                "這是學者帶的頭巾，相傳大軍師諸葛孔明曾穿著它參加赤壁之戰． \n"
                "談笑間，強虜灰飛煙滅，你不禁悠然神往.......\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "scholar");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "magic":5,"mental":2 ]) );
        set( "weight", 50 );
        set( "value", ({ 566, "gold" }) );
}



