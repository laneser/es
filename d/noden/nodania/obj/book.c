#include "/u/e/ega/ega.h"
inherit OBJECT;
int             create()
{
        set_name("book", "聖經");
        set_short("聖經");
        set_long(@CLONG
這是一本聖經。
CLONG
        );
        set("id", ({"book", "holy book"}));
        set("unit", "本");
        set( "weight", 0 );
        set ("value", ({ 1, "silver" }) );
        seteuid( getuid() );
}
