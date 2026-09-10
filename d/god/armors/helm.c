#include <mudlib.h>

inherit ARMOR;

string C_NAME="魔神頭盔";

void create()
{
        set_name( "damogorgod helmet", C_NAME );
        add( "id", ({ "helmet" }) );
        set_short( C_NAME );
        set_long(
                "無名之盔。\n"
        );
        set( "unit", "頂" );
        set( "type", "head" );
        set( "material", "knight" );
        set( "armor_class", 20 );
        set( "extra_skills", ([ "riding":20 ]) );
        set( "weight", 80 );
        set( "value", ({ 300, "gold" }) );
}
