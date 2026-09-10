// abyss6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("深淵");
    set_long(@C_LONG
你現在處於一個深淵的底部，四周圍繞著一片灰濛濛的霧氣。雖然是在濃
霧之中，但是你隱約覺得有許多眼睛正在窺伺著你，彷佛像地獄中探頭出來的
惡靈一般地鬼鬼祟祟。在這片黑暗之中，找到光明似乎正是你的當務之急。
C_LONG
    );
    set("item_desc", ([
	"bloodstrain" : "一片暗紅的血跡，旁邊還有個燭臺 (standard)。\n",
	"standard" : "燭臺裡有根錐 (bodkin)，上頭似乎有血跡。\n",
	"bodkin" : "這根椎如果戳 (prod) 在肉裡，肯定會很痛。\n"
	]) );

    set("exits", ([
	"northwest" : AREA"abyss3",
	"northeast" : AREA"abyss4",
	"north" : AREA"abyss5",
	"southwest" : AREA"abyss1",
	"southeast" : AREA"abyss2",
	"south" : AREA"abyss0"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_prod", "prod");
}

int to_search()
{
    write("你找了又找，發現地上畫著一個魔法陣，上面似乎有些血跡 (bloodstrain)。\n");
    return 1;
}

int to_prod()
{
    object p;
    p = this_player();

    p->receive_damage(5);
    tell_object(p, "你用尖錐戳了自己的手指一下 .... 好痛！流血了！ ....\n");
    tell_object(p, "你趕快把手指放到嘴裡吸吮，但還是有滴血滴到了地上 ....\n");

    if (p->query_temp("lilia_abyss") == 6)
    {
	p->set_temp("block_command", 1);
	tell_object(p, "地上的魔法陣突然發出光芒，強大的魔力衝擊著你每一根神經！\n");
    	call_out("activate", 15, p);
    }

    return 1;
}

int activate(object p)
{
    p->delete_temp("block_command");
    p->delete_temp("lilia_abyss");
    tell_object(p, "當你回過神來時，你發現眼前的景物已經變了...\n");
    p->move(AREA"abyss7");
    return 1;
}
