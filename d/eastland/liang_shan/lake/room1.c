#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你進入了一間低矮的房子，房子裡沒有什麼擺設，給人一種空空蕩蕩\n"
	"的感覺。牆上有一個小窗子，正對著梁山泊大湖，湖上的涼風，不時從窗\n"
	"戶中吹進來。窗下放著一張床，一個看來病的很重的老婆婆正躺在床上。\n"
	  );
        set("c_item_desc",(["bed":
"這是一張普通的木床，除了拿來睡覺以外，沒有其它的功能。上面的被褥都很\n"
"乾淨，由此看來這個老婆婆並不是無人照料。\n"
            ]));        
        set( "exits", ([
                "west" : TROOM"village2"
        ]));
        set( "objects", ([
                "lady" : TMONSTER"dapo"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 if ( !arg || arg != "bed")
    return notify_fail(
    "要找什麼?\n");
 if ( !present("da") ) 
    return notify_fail(
    "你在床上翻了半天，找不到任何可用的東西.....\n");
write(@ALONG
你在床上翻來翻去，不小心碰到老婆婆，把老婆婆嚇醒了，老婆婆啐了你一口
罵道: 小兔崽子，沒事在老孃床上作什麼? 你趕快起身站好
ALONG
		);
	        return 1;
}
