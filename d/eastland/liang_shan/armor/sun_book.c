#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("suntsu", "孫子兵法");
        add( "id", ({ "book" }) );
        set_short("孫子兵法");
        set_long(
                "這是聞名於世的孫子兵法，得到它就會擁有安邦定國之力...\n"
        );
        set( "unit", "本");
        set( "type", "misc" );
        set( "material", "scholar");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "mental":6, "none":-6 ]) );
        set( "weight", 30 );
        set( "value", ({ 1470, "silver" }) );
        set( "extra_skills",(["tactic":10]));
}
