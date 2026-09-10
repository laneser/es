
inherit "/std/pet.c" ; 

void init()
{
	::init();
    add_action( "order_me","order_bird");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet bird","精靈鳥");
        add( "id", ({ "bird","pet" }) );
        set_short( "迷路的精靈鳥");
        set_long(
@C_LONG
這隻鳥是某人的寵物，它喜歡跟著主人飛來飛去。它現在正
好奇地看著你。它的脖子上掛著一塊牌子，上面寫著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖小鳥，請不要隨便把我丟在路邊
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_bird <commands> 讓它聽話。
C_LONG
        );
        set_perm_stat("str", 1);
        set_perm_stat("con", 1);
        set_perm_stat("dex", 4);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set("max_load", 50);
        set("weight", 30);
        set("post_name","'s pet bird");
        set("c_post_name","的精靈鳥");
        set("prevent_give_money", 1);
        set("pet_type", "bird");
		set("tactic_func", "call_help");
        set_temp("effect/power-boost", 1);
        set_c_verbs( ({ "%s用嘴往%s啄去", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "精靈鳥啾啾的叫著，在你的肩膀跳來跳去。\n",
        "精靈鳥拍拍翅膀，在地上找東西吃。\n"
        }));
        setenv("C_MMIN","$N跟著它的主人飛了過來。");
        setenv("C_MMOUT","$N跟著它的主人飛開。");
}
