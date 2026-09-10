
inherit "/std/pet.c" ;

void init()
{
	::init();
     add_action( "order_me","order_rat");
     add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet rat","天竺鼠");
        add( "id", ({ "rat","pet" }) );
        set_short( "可愛的天竺鼠");
        set_long(
@C_LONG
這隻天竺鼠是某人的寵物，它喜歡跟著主人走來走去。它現在正用它那對
漆黑的小眼睛好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖鼠鼠，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_rat <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 1);
        set_perm_stat("con", 1);
        set_perm_stat("dex", 3);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 2);
        set("max_load", 50);
        set("weight", 50);
        set("post_name","'s pet rat");
        set("c_post_name","的天竺鼠");
        set("prevent_give_money", 1);
        set("pet_type", "rat");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "天竺鼠用它那對漆黑的眼睛好奇的看著你。\n",
        "天竺鼠爬進你的口袋，找出一塊餅乾，高興地吃起來。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
