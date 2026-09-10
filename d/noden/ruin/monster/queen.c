// Lilia the Queen
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Lilia the Queen", "女王 莉莉雅");
    add("id", ({"lilia", "queen"}));
    set_short("女王 莉莉雅");
    set_long(@C_LONG
威嚴地坐在王座上的，想必就是傳說中的魔族真神□女王，不過她看來氣
色不是很好，似乎是太過於勞累了。或許你可以替女王加油打氣一番，讓她高
興一點。
C_LONG
	    );
    set("gender", "female");
    set("race", "drow");
    set("unit", "個");
    set("no_attack", 1);
    set("inquiry", ([
	"airshield" : "@@ask_airshield",
	"home" : "@@ask_home"
	]) );
}

void init()
{
    add_action("to_cheer", "cheer");
}

int to_cheer(string arg)
{
    if (arg == "lilia" || arg == "queen" || arg == "女王")
    if ((int)this_player()->query(QUESTNAME) == 7)
    {
 	write("女王拍拍你的頭，說道：「真是個好孩子。」\n");
	write("[你完成了 失落的封印 的任務，獲得 3000 點經驗]\n");
	this_player()->finish_quest(QUESTNAME,3);
	this_player()->gain_experience(3000);
	this_player()->set(QUESTNAME, 9);
	return 1;
    }

    write("女王說道：「要我送你回家 (home) 直說就好啦，別拍馬屁了。」\n");
    return 1;
}

void ask_airshield(object p)
{
    if ((int)p->query(QUESTNAME) != 9)
    {
	tell_object(p, "女王斜眼瞄了你一下，然後就沒有任何反應了，看來她心情似乎不太好。\n");
	return;
    }

    if (p->query("class") != "healer")
    {
	tell_object(p, "女王打量了你一下，說道：「你不是醫生，問這東西幹什麼？」\n");
	return;
    }

    p->set(QUESTNAME, 8);
    tell_object(p, "女王說道：「乖孩子，現在我賜給你聚氣 (amass) 的能力，你要好好運用喲！」\n");
    tell_room(environment(p), "女王喃喃地念起咒文 ....\n", ({}));
    tell_object(p, "霎時間，你突然領會到導氣可以成盾的道理，你學會了氣盾術！\n");
    return;
}

void ask_home(object p)
{
    tell_object(p, "女王說道：「好孩子，回藍沙港去找邢老爹玩耍吧！」\n");
    tell_object(p, "女王話剛說完，你忽然覺得眼前一花 ....\n");
    p->move("/d/healer/building/healer_guild");
    return;
}
