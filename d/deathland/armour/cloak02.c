#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black cloak", "黑鬥蓬");
        add( "id", ({ "cloak" }) );
        set_short("black cloak", "黑鬥蓬");
        set_long(
                "A black robe prayed by Evil Yang,a legendary evil_god .\n",
                "被用來祭祀傳說邪神Yang的一件黑袍\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_denfese", ([ "evil":4, "divine":-6 ]) );
        set( "weight", 50 );
        set( "value", ({ 1600, "silver" }) );
}
