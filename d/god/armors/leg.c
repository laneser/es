#include <mudlib.h>

inherit ARMOR;

string C_NAME="魔神脛甲";

void create()
{
        set_name( "demogorgod leggings", C_NAME );
        add( "id", ({ "leggings" }) );
        set_short( C_NAME );
        set_long(
                "無名脛甲。\n"
        );
        set( "unit", "副" );
        set( "type", "legs" );
        set( "material", "knight");
        set( "armor_class", 15);
        set( "extra_skills", ([ "riding":20 ]) );
        set( "weight", 80 );
        set( "value", ({ 300, "gold" }) );
}
