#include "pets.h"

inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_dino");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(2);
        set_name("pet dino","小火龍");
        add( "id", ({ "dino","pet" }) );
        set_short( "沒人管的小火龍");
        set_long(
@C_LONG
這隻小火龍是某人的寵物，它喜歡跟著主人走來走去。它現在正用它那對
可愛的紫色眼睛好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖恐龍，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_dino <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 7);
        set_perm_stat("con", 5);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 200);
        set("weight", 900);
        set_temp("effect/power-boost", 1);
        set("post_name","'s pet dino");
        set("c_post_name","的小火龍");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "小火龍打了一個哈欠，噴出一團團紫色的煙。\n",
        "小火龍拉著你的手說：「我要吃蜥蜴尾巴」。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
