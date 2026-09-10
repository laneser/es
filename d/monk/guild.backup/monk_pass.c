#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/water_board"

inherit ROOM;
void create()
{
	::create();
	set_short("A monk guild", "羅漢堂穿堂");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡是羅漢堂前的穿堂，往東走便可以到達羅漢堂。這是個十分狹窄的穿堂
穿堂中唯一吸引你注意的是牆邊掛著一幅大大的牌子，上面寫著一個大大的『灌  
』字。牌子旁邊有幾行字(words)你不妨先看看。 
往南可通往武僧訓練房。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"words" : @LONG_TEXT
————————————————————————————————
因為留言板在留言數達 30 時會自動清除，故特設此板為灌水專用板 
歡迎十方大德來此灌水。

而羅漢堂內之留言板則專做宣佈有關公會事項，bug 報告及建議時使用 
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
 	    "east" : SAULIN"monk_guild",
 	    "south" : SAULIN"train_room",
		"west" : "/d/eastland/saulin_temple/hallway23",
    ]));
	set("no_monster", 1);
	BOARD->frog();

}
