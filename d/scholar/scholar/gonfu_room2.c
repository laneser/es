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
公會的人才能進來，大廳中央有好幾本記載劍術心法的書(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
書上有寫著一些劍術心法如果你想學的話可以用 train <劍術名稱> 學得。

           劍法：   所需等級  所需古文技能  虔誠屬性限制

      宋詞劍法(song)     5         30            5
      唐詩劍法(tang)    10         55           10
      漢賦劍法(han)     15         80           15

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/hall" ]) );
    set_gonfus(([
          "song"        : ({  5  , 30  ,  5   }),
          "tang"        : ({  10 , 55  ,  10  }),
          "han"         : ({  15 , 80  ,  15  }),
	]));
	reset();
}
