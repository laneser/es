#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "拍賣廣播網播音室" );
	set_long(@C_LONG
這裡就是著名的拍賣廣播網的播音室，不是很大的一個房間被一面晶瑩
剔透的魔法水晶牆分割成兩半，牆的那邊有幾名年輕貌美的女郎正聚精會神
地運用魔法水晶的法力主持著拍賣的進行，牆的這邊卻堆滿了等待拍賣的東
西和一些奇形怪狀的魔法道具，顯得十分雜亂。
C_LONG
	);
	set( "light",1 );
	set( "objects", ([
      	        "guardian" : "/d/noden/farwind/monster/auc_guard"
        ]) );
	set( "exits", ([
                "north" : "/d/noden/farwind/bazz2",
        ]) );
	
	reset();
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	tell_object(this_player(),
	"你伸出手來，可是發覺一切的東西似乎都十分沈重，彷佛被吸住了一般。\n");
	return 1;
}
int clean_up() { return 0; }
