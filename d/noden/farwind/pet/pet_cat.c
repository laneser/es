
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_cat");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet cat","喵喵貓");
        add( "id", ({ "cat","pet" }) );
        set_short( "迷途的喵喵貓");
        set_long(
@C_LONG
這隻貓是某人的寵物，它喜歡跟著主人走來走去。它現在正用它那對美麗的
藍眼睛好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖貓咪，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_cat <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set_temp("effect/power-boost", 1);
        set("max_load", 75);
        set("weight", 100);
	set("post_name","'s pet cat");
        set("c_post_name","的喵喵貓");
        set("prevent_give_money", 1);
        set("pet_type", "cat");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "貓咪喵喵叫了幾聲，在你的腳邊挨挨擦擦的走來走去。\n",
        "貓咪拱起了背，伸伸懶腰，開始用爪子洗臉。\n"
        }));
        setenv("C_MMIN","$N用優雅慵懶的步子走了過來。");
        setenv("C_MMOUT","$N用優雅慵懶的步子走開。");
}
