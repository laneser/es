
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action( "order_me","order_pig");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet pig","迷你豬");
        add( "id", ({ "pig","pet" }) );
        set_short( "到處找東西吃的迷你豬");
        set_long(
@C_LONG
這隻迷你豬是某人的寵物，它喜歡跟著主人走來走去。它現在正用它那對
漆黑的眯眯眼好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖小豬，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_pig <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 3);
        set_perm_stat("dex", 1);
        set_perm_stat("int", 1);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 2);
        set("max_load", 75);
        set("weight", 200);
        set("post_name","'s pet pig");
        set("c_post_name","的迷你豬");
        set("prevent_give_money", 1);
        set("pet_type", "pig");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的頭拱%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "迷你豬用它的鼻子到處聞來聞去。\n",
        "迷你豬搖著它的短尾巴，繞著你轉來轉去。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人走了過來");
        setenv("C_MMOUT","$N跟著它的主人走開");
}
