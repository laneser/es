#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("pack of herbs","藥包");
        add( "id" , ({ "pack" }) );
        set_short("a pack of herbs" , "藥包");
        set_long("This is a pack of herbs .\n" ,
		 "這是一大包包著各種藥材的紙包，聞起來有濃郁的藥草香。\n");
        set("unit","包");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
