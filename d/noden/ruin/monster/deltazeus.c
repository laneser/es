// Adventurer Delta Zeus
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    seteuid(getuid());
    set_level(1);
    set_name("Delta Zeus", "考古學家 達特紐斯");
    add("id", ({"delta", "zeus"}));
    set_short("考古學家 達特紐斯");
    set_long(@C_LONG
站在你面前的這位先生，就是頂頂大名的考古學界鬼才達特紐斯，也是個
非常有名的冒險家。達特紐斯先生前些日子為了考查傳說中的魔族古帝國遺蹟
而失蹤了，沒想到竟出現在這裡，或許你可以問問他有關遺蹟 (ruin) 的事情
來滿足一下你小小的好奇心。
C_LONG
	    );
    set("gender", "male");
    set("race", "human");
    set("unit", "個");
    set("no_attack", 1);
    set("inquiry", ([
	"ruin" : "@@ask_ruin",
	"rune" : "@@ask_rune"
	]) );
}

void ask_ruin(object p)
{
    tell_object(p, @RUIN
遺蹟? 呵呵呵 .... 年輕人，你現在就站在魔族古帝國第一大城羅斯托麗
城的土地上啦! 如果你對魔族古帝國的事蹟有興趣的話，這裡是最好的教室，
但是得要你自己努力去尋找才行。
RUIN
	);
    return;
}

void ask_rune(object p)
{
    object dic, *items;
    int i;

    tell_object(p, @RUNE
哦，那個碑文啊? 那是古代魔族的文字，碑文裡面只寫了四個字：「芝麻
開門」，我還沒推敲出來它的意思呢。年輕人，如果你對魔族的碑文有興趣，
這本魔法字典送給你，它可以幫助你閱讀魔族的古文。
RUNE
	);
    items = all_inventory(p);
    for (i = 0; i < sizeof(items); i++)
   	if ((string)items[i]->query("name") == "Rune Dictionary")
	{
	    tell_object(p, "咦? 你已經有這本字典啦? 那我還是留著好了。\n");
	    return;
	}

    dic = new(OBJ"dictionary");
    dic->move(p);
    p->set_temp("lilia_dic", 1);
    return;
}

