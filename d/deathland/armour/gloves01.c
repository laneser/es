#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silk gloves", "絲質手套");
        add( "id", ({"gloves" }) );
        set_short("a silk gloves", "絲質手套");
        set_long(
                "An gloves made of silk.\n",
                "一雙絲質手套,可以讓武器的使用更加流暢\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
        set( "defense_bonus", 2 );
        set( "extra_skills", ([ "parry":3 ]) );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}
