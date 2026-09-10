#include <mudlib.h>

inherit OBJECT;

int cutted;

void create()
{
    set_name( "wolf heart", "狼心" );
    add( "id", ({ "heart" }) );
    set_short( "狼心" );
    set( "unit", "顆" );
	set("long","@@query_c_long");
    set( "weight", 10 );
    cutted = 0;
}

string query_c_long()
{
    if( cutted )
        return "這是一顆被切成一團稀爛的狼心, 你越看越感噁心。\n";
	else
        return "這是一顆血淋淋的狼心, 似乎沒什麼利用價值。\n";
}

int query_cutted() { return cutted; }

void init()
{
    add_action( "cut_heart", "cut" );
}

int cut_heart(string arg)
{
    object cleaver;

    if( !arg || ( arg!="heart" && arg!="wolf heart") )
        return notify_fail("你要切什麼東西？\n");
    if( cutted )
        return notify_fail("這顆心已經被切過了。\n");

    cleaver = present("cleaver",this_player());

    if( !present("cleaver",this_player()) )
        return notify_fail("你最好找把適當的刀來切它。\n");

    cutted = 1;
    write("你拿起屠刀把狼心大解八塊。\n");
	return 1;
}


