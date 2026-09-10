// Archfiend
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("Archfiend", "黑天使 亞奇芬德");
    add("id", ({"archfiend", "devil"}));
    set_short("黑天使 亞奇芬德");
    set_long(@C_LONG
獰笑的面孔，黑亮的翅膀，外加頭上的三隻角，不用說你也知道站在你面
前的是冥府的老大黑天使亞奇芬德，外號撒旦的便是。看來想要走出這裡，必
須和他老人家談筆交易 (trade) 才成。
C_LONG
	    );
    set("gender", "male");
    set("race", "vampire");
    set("unit", "位");
    set("no_attack", 1);
    set("inquiry", ([
	"trade" : "@@ask_trade",
	"dedicate" : "@@ask_dedicate",
	"question" : "@@ask_question"
	]) );
}

void init()
{
    ::init();
    add_action("to_answer", "answer");
}

void ask_trade(object p)
{
    tell_object(p, @TRADE
亞奇芬德斜著眼打量了你好一會兒，然後慢條斯理的說道：「你想找齊七個封
印好去見那個變態女王啊? 真是勇氣可嘉呀! 為了表示我對勇者的崇敬，你可
以選擇把你的靈魂奉獻 (dedicate) 給魔鬼，或是回答我的謎題 (question)
來得到我手中的弗雷斯之印。不過我先警告你，如果你沒有辦法正確地回答我
的謎題，那你的靈魂會自動地奉獻給魔鬼，而且你也得不到弗雷斯之印。至於
靈魂要怎麼奉獻嘛 .... 等你到了遠風鎮你自然會明白呵呵。決定好了之後，
問 (ask) 我奉獻 (dedicate) 或謎題 (question)。」
TRADE
	       );
    return;
}

void ask_dedicate(object p)
{
    tell_object(p, "亞奇芬德大笑道：「好個爽快的傢伙，我會叫黑無常拿弗雷斯印給你！」\n");
    this_player()->set(QUESTNAME, 4);
    tell_object(p, "一陣霹靂閃電忽然打在你的身上，你感到眼前一黑 ...\n");
    tell_room(environment(p), "亞奇芬德發出了一陣狂笑，隨即召喚來一陣天雷直直地劈在"+p->query("c_name")+"的身上！\n", p);
    this_player()->receive_damage(2000);
    return;
}

void ask_question(object p)
{
    tell_object(p, @QUES
亞奇芬德說道：「只要你告訴我，東方故事裡最變態的巫師是誰，答對的話，
我就履行我的諾言。你不必急著回答我，當然，答錯了的話，你必須付出你的
生命當代價。」
QUES
	       );
    this_player()->set_temp("lilia_devil", 1);
    return;
}

int to_answer(string s)
{
    object p;
    p = this_player();

    if (!s || p->query_temp("lilia_devil") != 1 || p->query(QUESTNAME) >= 4)
	return notify_fail("你想答什麼？\n");

    if (s != "lilia" && s != "調教師" && s != "女王")
    {
	tell_object(p, "亞奇芬德大笑道：「這麼簡單的題目也不會？死來！」\n");
        tell_object(p, "一陣霹靂閃電忽然打在你的身上，你感到眼前一黑 ...\n");
        tell_room(environment(p), "亞奇芬德發出了一陣狂笑，隨即召喚來一陣天雷直直地劈在"+p->query("c_name")+"的身上！\n", p);
        p->receive_damage(2000);
    }
    else
    {
	tell_object(p, @LAUGH
亞奇芬德大笑道：「聰明的傢伙，一屁中彈！我已經履行了我的諾言，
把弗雷斯印送給你了。順便做點沙密斯給你好了，你要記好，在死亡迷
宮裡，要依著女王的名前進。去吧！聰明的傢伙！」
LAUGH
		   );
	tell_object(p, "亞奇芬德啪的一聲在你頭上打了一記，你覺得眼前一黑 ....\n");
        write("[你完成了 失落的封印 第二階段的任務，獲得 2000 點經驗]\n");
        this_player()->finish_quest(QUESTNAME, 2);
        this_player()->gain_experience(2000);
	this_player()->set(QUESTNAME, 4);
	p->move(AREA"rose4");
    }

    return 1;
}   
