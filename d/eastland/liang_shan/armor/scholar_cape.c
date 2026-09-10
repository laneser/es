#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("scholar cape", "軍師護袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("scholar cape","軍師護袍");
        set_long(
                "This is a cape for great scholars only.\n",
                "這是一件型式高古的長袍，上面寫了一些彎彎曲曲的蝌蚪文字．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "scholar" );
        set( "armor_class", 6 );
        set( "defense_bonus", 10 );
        set( "special_defense",(["evil":-3,"cold":-10,"fire":2,"divine":4 ]) );
        set( "weight", 70 );
        set( "value", ({ 1375, "silver" }) );
        set( "extra_skills",(["inner-force":10]));
}