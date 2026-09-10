#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "huge hammer", "大□頭" );
        add( "id", ({ "hammer" }) );
        set_short("大□頭");
        set_long(
                "這是一支和樹幹差不多大隻的大□頭，看來相當沉重。\n"
        );
        set( "unit", "支" );
        setup_weapon( "blunt", 25, 11, 28 );
        set( "weight", 300 );
        set( "value", ({ 50, "silver" }) );
}
