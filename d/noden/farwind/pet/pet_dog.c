
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_dog");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet dog","大笨狗");
        add( "id", ({ "dog","pet" }) );
        set_short( "懶惰的大笨狗");
        set_long(
@C_LONG
這隻狗是某人的寵物，它喜歡跟著主人走來走去。它現在正用它那對柔和的
眼睛好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖狗狗，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_dog <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 3);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 100);
        set("weight", 250);
        set("post_name","'s pet dog");
        set("c_post_name","的大笨狗");
        set("prevent_give_money", 1);
        set("pet_type", "dog");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "狗狗搖著它的尾巴，想要跟你玩。\n",
        "狗狗趴到你身上，把你舔的滿臉口水。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
