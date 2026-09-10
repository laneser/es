#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("amaze root","奇異花的根");
        add( "id" , ({ "root" }) );
        set_short("奇異花的根");
        set_long("這是一段黑黑的、不起眼的樹根。\n");
        set("unit","段");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
