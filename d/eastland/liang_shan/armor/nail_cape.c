#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("nail cape", "七星打釘皂羅袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("nail cape","七星打釘皂羅袍");
        set_long(
                "This is cape with some nails on it.\n",
                "這是一件寬大的護袍，一點也不會妨害行動，上面釘了些裝飾的釘子．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":3,"divine":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 890, "silver" }) );
        set( "extra_skills",(["dodge":10]));
}