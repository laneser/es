#include "../../story.h"

inherit "/std/bank";
inherit "/std/exchange";
inherit ROOM;

void create()
{
	exchange::create();
	room::create();
	set_short("錢莊");
	set_long( @LONG
這裡是東方故事裡所有錢莊的連鎖店之一。自從在北山發現金礦之後，一時城
裡的人都跟著富有起來，餘錢也就愈來愈多，再加上人民有儲蓄的習慣，所以銀行
的事業也就跟著蒸蒸日上。你可以在這裡 存(deposit) 提(withdraw) 款，或者是
在這裡用 25 枚金幣開個戶頭 (open account) ，就可以將你的錢寄放在錢莊裡。
另外在這裡也提供兌換服務，你可以用(convert) 指令兌換身上的錢幣，所有流通
的錢幣種類都寫在牆壁的一張佈告 (sign) 上。
LONG
	);
	set( "light", 1 );
	set( "exits", ([ 
           "north" : SCITY"nw1" ]) );
	reset();
}
void init()
{
	bank::init();
	exchange::init();
}
