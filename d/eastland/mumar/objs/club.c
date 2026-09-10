#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "club", "警棍" );
        add( "id", ({ "club" }) );
        set_short("警棍" );
        set_long(
                "這是一支一般巡邏兵用的木棍。\n"
        );
        set( "unit", "支" );
        setup_weapon( "blunt", 5, 3, 6 );
        set( "weight", 60 );
        set( "value", ({ 20, "silver" }) );
}
