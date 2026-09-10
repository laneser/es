#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name( "iron key","禁地鑰匙");
        add( "id", ({ "key" }) );
        set_short( "iron key", "禁地鑰匙");
        set_long(            
                "這是一把開啟禁地大鐵門的鑰匙。\n"
        );
        set( "unit", "把" );
        set( "to_lock", "IRON_DOOR" );
        set( "weight", 5 );
        set( "value", ({ 30, "silver" }) );
        set( "no_sale", 1 );
}
