// rose5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。城市大道在這
裡被瓦礫堆給堵死了。這片殘破蕭條的景像和城門附近雄偉瑰麗的建築真是個
極為諷刺的對比，你的直覺告訴你還是往回走才能找到出路。
C_LONG
    );
    set("exits", (["south" : AREA"rose4"]) );
    set("item_desc", ([
	"door" : @DESC
秘門上畫了不少奇怪的圖案，看起來像是某種無聊的塗鴉。門旁邊還散落了
不少的木炭，似乎就是拿來塗鴉 (draw) 用的。
DESC
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_draw", "draw");
    add_action("to_open", "open");
}

int to_search(string s)
{
    if (s == "door")
    {
	write("門後面似乎有風的聲音 ....\n");
    }
    else
    {
        write("瓦礫堆的下面似乎有個秘門 ....\n");
    }
    return 1;
}

int to_draw(string s)
{
    object p;
    p = this_player();

    if (!s)
	return notify_fail("把什麼畫在什麼上面？(draw A on B)\n");

    if (s == "seal on door" || s == "seal o pallass on door" ||
	s == "Seal o Pallas on door")
    {
	if (p->query(QUESTNAME) >= 2)
	{
	    tell_object(p, "你小心翼翼地把巴拉斯之印畫在秘門上 ...\n");
	    p->set_temp("lilia_wind", 1);
	    return 1;
	}
    }
    return notify_fail("你想畫什麼？\n");
}

int to_open(string s)
{
    object p;
    p = this_player();

    if (s == "door")
    {
	if (p->query_temp("lilia_wind") != 1)
	    return notify_fail("你用盡了吃奶的力氣，還是打不開這道門。\n");
	p->delete_temp("lilia_wind");
	tell_object(p, "當你的手剛摸到門把的時候，門忽然自動地打開，一陣狂風將你捲進門內!\n");
	p->move(AREA"eda0");
	p->receive_damage(5);
        return 1;
    }
    else 
	return notify_fail("你想開什麼？\n");
}    
