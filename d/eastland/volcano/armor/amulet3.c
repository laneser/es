#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("holy amulet", "神聖護身符");
        add( "id", ({ "amulet" }) );
        set_short( "神聖護身符");
        set_long(
                "這個護身符能抗拒所有的邪惡。\n"
        );
        set("unit","個");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "evil":10 ]) );
        set( "weight", 50 );
        set( "value", ({ 300, "gold" }) );
}






