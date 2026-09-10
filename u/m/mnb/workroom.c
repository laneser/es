#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
        set_short( "寒鴉的小被窩" );
        set_long(
                "這是寒鴉和他的女人睡覺的地方,所以。。。沒有事可別進來哦！\n"
	);
        set( "light",1 );

        set( "exits", ([

                "guild" : "/d/wiz/wiz_hall",
        ]) );
     reset();
}

