
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("blue ring", "藏青色的誘惑");
	seteuid(getuid());
        add( "id", ({ "blue ring","ring" }) );
        set_short( "藏青色的誘惑" );
        set("long","這是一枚青綠色的戒指，上面刻著：維多吾愛\n");
        set( "weight", 3 );
        set( "unit", "枚" );
}
