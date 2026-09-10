#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("jade chainmail", "翡翠□甲");
        add( "id", ({ "mail","chainmail" }) );
        set_short("翡翠□甲");
        set_long(
                "這是一件以翡翠製成的□甲看起來十分華麗。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "element" );
        set( "armor_class", 28 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine" :5, "magic":-7 ]) );
        set( "weight", 200 );
        set( "value", ({ 200, "gold" }) );
}