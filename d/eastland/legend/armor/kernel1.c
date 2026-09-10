#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name( "purple kernel", "紫晶核" );
    add( "id", ({ "kernel", }) );
    set_short( "紫晶核" );
    set_long(@LONG 
    一顆奇特的晶石，散出深遂美麗的紫色光芒，並從你手上接觸的地方傳來一股
源源不絕的能量，不知道有什麼特殊作用。     
LONG      );
    set( "unit", "顆" );
    set( "type", "kernel" );
    set( "material", "element" );
    set( "defense_bonus", 5 );
    set( "weight", 60 );
    set( "value", ({ 3, "silver" }) );
}
