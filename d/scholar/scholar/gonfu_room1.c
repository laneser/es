#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
        set_short("Sword room", "冬菊軒");
	set_long(
@C_LONG_DESCRIPTION
你進入了舞墨軒的劍法練習室冬菊軒，這裡是書生們習武練劍的地方，只有書生
公會的人才能進來，大廳中央有一本記載劍術心法的書(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
書上有寫著一些劍術心法如果你想學的話可以用 train <劍術名稱> 學得。

劍術     ： 宋詞劍法(song) (level 5)
            唐詩劍法(tang) (level 10)
            漢賦劍法(han)  (level 15)

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/hall" ]) );
    set_gonfus(([
          "song"        : ({  5 ,    1500 }),
          "tang"        : ({  10,   10000 }),
          "han"         : ({  15,   15000 }),
	]));
	reset();
}
