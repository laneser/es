#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name( "altar key", "白魔法鑰匙" );
        add( "id", ({ "key" }) );
        set_short( "an altar key", "白魔法鑰匙" );
        set_long(
                "A long iron key.\n",
                "這是用來開啟通往白魔法圖書館的鑰匙。\n"
        );
        set( "unit", "把" );
        set( "to_lock", "1" );
        set( "weight", 3 );
        set( "value", ({ 0, "silver" }) );
        set( "no_sale", 1 );
}
