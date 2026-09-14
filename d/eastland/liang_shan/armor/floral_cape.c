#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("floral cape", "百花點翠皂羅袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("floral cape","百花點翠皂羅袍");
        set_long(
                "This is a green cloak with some floral mark.\n",
                "這是一件翠綠的鬥蓬，上面點綴著無數的白花圖形，就像是走在\n"
                "春天的草原，你覺得人生充滿希望...\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 1100, "silver" }) );
}