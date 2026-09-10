#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("茅屋");
	set_long(@C_LONG
一走進這屋子，你聞到一股濃濃的藥味，有點噁心。屋裡有各種煉藥用的
工具，什麼煉丹爐、藥缽、藥杵，應有盡有。牆上掛了一些奇奇怪怪的東東，
看起來像是曬過的藥材。靠窗的一邊有個桌子，桌上有些小小工具。
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room2.c",
		"east" :  WANG"room4" // 書房
	]));

	set("objects", ([
		"boy"  : WANG_MOB"boy02.c",
	]) );

	set( "c_item_desc" , ([
		"table" : "桌上擺了些白瓷做的藥缽，有層綠綠的垢，看起來使用過一段時間了。\n",
		"oven"  : "一個小巧的煉丹爐，爐火還蠻旺的，不曉得正在練啥丹藥\n"
			  "說不定是太上老君的啥神丹妙藥，你不禁有點好奇。\n",
	]));

	set( "search_desc", ([
		"oven" :    "@@search_oven",
		"煉丹爐" :  "@@search_oven",
		"爐" :      "@@search_oven",
	]));
	reset();
}

string search_oven()
{
		return "這爐子太燙了，你不敢打開來看。\n";
}


