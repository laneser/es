// bard.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Bard Xerox", "吟遊詩人 紀羅斯");
    add("id", ({"bard", "xerox"}));
    set_short("吟遊詩人 紀羅斯");
    set_long(@C_LONG
深紫色的頭髮，湛藍的眼睛，搭配著黑暗精靈獨有的臉色，和吟遊詩人獨
有的吊兒郎當的悠閒氣質，你發覺紀羅斯是個很有魅力的混合體。嗯，或許該
說是很有魅力的男人。不過由他腰間那閃閃發亮的銀笛看來，和他做朋友要比
和他做敵人來的愉快的多。
C_LONG
     	);
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 30);
    set_perm_stat("dex", 20);
    set_perm_stat("pie", 20);
    set_perm_stat("kar", 20);
    set_skill("dodge", 100);
    set_skill("blunt", 85);
    set("race", "drow");
    set("gender", "male");
    set("hit_points", 1200);
    set("max_hp", 1200);
    set("aim_difficulty", (["critical" : 80, "weakest" : 80]));
    set("special_defense", (["all" : 30, "none" : 30, "monk" : 20, "scholar" : 20]));
    set_natural_armor(30, 40);
    set_natural_weapon(20, 25, 40);
    wield_weapon(WP"flute.c");
    equip_armor("/d/deathland/armour/cloth03.c");
    set("chat_chance", 10);
    set("chat_output", ({
	"紀羅斯唱道：「給我一個吻，可以不可以？」\n",
	"紀羅斯唱道：「留在我的臉上，做個愛標記。」\n",
	"紀羅斯唱道：「Seven lonely days make a lonely week ...」\n", 
	"紀羅斯唱道：「Seven lonely nights make a lonely me ...」\n"
	}));
    set("inquiry", ([
	"carmue" : "@@ask_carmue",
	"paladin" : "@@ask_carmue", 
	"statue" : "@@ask_statue"
	]));
}

void ask_carmue(object p)
{
    tell_object(p, @CARMUE
你說那個酷哥呀？他是女王座下三大騎士之一唷 .... 兇的很哪 .... 沒事不要惹
他，除非你想去找老黑泡茶呵呵 ....
CARMUE
		);
    return;
}

void ask_statue(object p)
{
    tell_object(p, @STATUE
那個不是雕像，那是個因為偷漢子遭到女王咀咒的可憐女人。如果你還有點同情心
的話，摘 (pick) 幾朵花去供在祭壇上吧。
STATUE
		);
    return;
}

