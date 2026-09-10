#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "occult globe", "青靈護盾圓球" );
    add( "id", ({ "globe", }) );
    set_short( "青靈護盾圓球" );
    set_long(@LONG 
    一個球狀的反物質,像是一種護盾產生器。
LONG      );
    set( "unit", "種" );
    set( "type", "globe" );
    set( "material", "element" );
    set( "defense_bonus", 10 );
    set( "weight", 100 );
    set( "value", ({ 200, "silver" }) );
}
