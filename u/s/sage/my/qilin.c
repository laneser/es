#include "pets.h"

inherit "/u/s/sage/test/pet.c" ;

void init()
{
        ::init();
    add_action("order_me","order_qilin");
    add_action("help_order", "help");
}

void create()
{
        ::create();
     set_level(19);
     set_name("qilin","火麒麟");
        add( "id", ({ "dino","pet" }) );
      set_short( "火麒麟");
        set_long(
@C_LONG
    這種動物據說是在500000年前已經絕種的史前生物，他能夠帶給主人
無限的運氣和福氣能成為它的主人的人，必須是一個非常善良勇敢的人，
它將會守護著你一生。
如果你是它的主人，你可以用 order_qilin <commands> 讓它聽話。
C_LONG
        );
      set_perm_stat("str", 30);
     set_perm_stat("con", 30);
     set_perm_stat("dex", 30);
     set_perm_stat("int", 30);
     set_perm_stat("pie", 30);
     set_perm_stat("kar", 30);
     set("max_load", 200000);
        set("weight", 900);
        set( "hit_points", 200000 );
        set( "max_hp", 200000 );
        set_skill( "defend", 100 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
     set_temp("effect/power-boost", 100);
     set("post_name","'s qilin");
     set("c_post_name","的火麒麟");
        set("prevent_give_money", 1);
        set("pet_type", "dino");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
     "火麒麟伸個懶腰，噴出一團團黑色的火。\n",
     "火麒麟舔著你的臉說：「你好美噢」。\n",
     "火麒麟陶醉地說：聖人好英俊噢。\n",
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
