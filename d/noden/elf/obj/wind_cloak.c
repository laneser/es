#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("fur cloak", "獸皮披風");
        add( "id", ({ "cloak" }) );
        set_short( "獸皮披風" );
        set_long(
                "這是精靈用獸皮所烘製成的披風。\n"
        );
        set( "unit", "件");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set( "weight", 40 );
        set( "value", ({ 280, "silver" }) );
}
