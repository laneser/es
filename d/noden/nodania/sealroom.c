#include <mudlib.h>

inherit ROOM;

void create()
{
	set_short("封印之廳");
	set_long( @LONG_DESCRIPTION
你現在來到一間幽暗的大廳，在你的面前，也就是大廳的南邊，一塊巨大
的巨巖(rock)堵住了整個大廳的南邊，你仔細一看，發現似乎這個城堡就是依
傍著這塊巨巖建造的，大廳沒有任何窗戶，只有東西兩排火把發出的微光照亮
著，你注意到大廳的正中央立著一個石碑(tablet)。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
	     "north" : "/d/noden/nodania/tower1" ]) );
	set( "item_desc", ([ 
	     "tablet" : @LONG_TEXT
石碑上只有短短的一行字:

    此地封印著通往米達爾(Mydarr)之墓穴的入口，任何人不準進入。
LONG_TEXT
, 
		"rock" : "這塊巨巖看起來年代相當久遠了，在火光的照耀下呈現出一種異樣的血紅色。\n" ]) );
	reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string str)
{
    if (!str)
	return notify_fail("你想找什麼東西?\n");
    if (str == "tablet")
    {
	tell_object(this_player(), "這個石碑似乎是某種開關 ....\n");
	return 1;
    }
    if (str == "rock")
    {
	tell_object(this_player(), "別呆了，你不可能推動這塊巨巖的 ....\n");
	return 1;
    }
}

int to_push(string str)
{
    object p;
    p = this_player();

    if (!str)
	return notify_fail("你想推動什麼東西?\n");
    if (str != "tablet")
	return notify_fail("你用盡了吃奶的力氣，還是推不動它。\n");
    if ((int)p->query_perm_stat("str") < 12)
	return notify_fail("太重了，你推不動 ....\n");
    else
    {
	tell_object(p, @FACE
當你推開石碑的那一剎那，巨巖忽然化成了一張猙獰的鬼臉!!

鬼臉突然伸出它長長的舌頭，將你捲進它的嘴裡!!

(你來到一個新的地方)

FACE
		   );
	tell_room(environment(p), sprintf("你聽到一聲淒厲的慘叫，回頭一看%s已經不知所終了。\n", p->query("c_name")), ({p}));
     p->move_player("/d/noden/ruin/room/en0","SNEAK");
    }
    return 1;
}

