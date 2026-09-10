
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("iron", "熨斗");
        add( "id", ({ "iron" }) );
        set_short( "熨斗" );
        set("long","這是一個大大的熨斗，看起來可以熨乾(dry)溼掉的衣服。\n");
        set( "weight", 40 );
        set( "unit", "個" );
}
