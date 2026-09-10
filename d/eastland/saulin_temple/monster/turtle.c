#include "/d/noden/moyada/moyada.h"
inherit MONSTER;

void create ()
{
    object ob1;
	::create();
	seteuid( getuid() );
	set_level(14);
	set_name( "Fast turtle", "快速龜" );
	add ("id", ({ "turtle", }) );
	set_short( "快速龜" );
	set_long( @C_LONG
你看到一隻穿跑鞋綁頭巾的小烏龜,它有一雙大大的眼睛,翠綠的身體...
它是傳說中風神養的烏龜,可別讓它一下子就溜走啦!!!。
C_LONG
	);
	set( "alignment", 2000 );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
	set ("natural_weapon_class1", 250);
	set ("natural_defense_bonus",10);
	set ("natural_armor_class", 25);
	set ("natural_min_damage1", 3); 
	set ("natural_max_damage1", 5);
	setenv( "C_MIN", "一隻$N很快的跑了過來。");
	setenv( "C_MOUT", "$N快速的往$D方跑走了。");
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 1, ]) );
	set ("special_defense",
	    ([ "all" : 10, "none" : 10 ]) );
	set ("wimpy", 50);
	set ("moving", 1);
        set ("speed",50);
    set ("weight", 100);
    set ("exp_reward", 3000);
    set ("chat_chance",14);
    set ("chat_output", ({
"『你知道龜兔賽跑 烏龜為什麼會贏嗎? 因為是由我代表參加啦!!!』『哈哈!!!』\n"
    }) );
    
set("att_chat_output",({
   "哈哈哈!!! 憑你們是抓不到我的啦!!! \n" ,
   "哈哈哈!!! 放棄吧!!! 去抓幸運兔啦!!! 慢腳蝦!!! :p\n"
   }));
 
    set_c_verbs( ({ "一下彈起用它的龜殼敲向你的背上", "用尾巴掃你的腦袋",
                    "在你的背上畫一隻大烏龜!!!" }) );
    set_c_limbs( ({ "龜甲","四肢","尾巴","鼻子"  }) );
    set( "c_death_msg", 
"%s說:『大哥 我認輸!!! 明年由你代表烏龜去比賽好了!!!』它搖搖頭,然後就死了。\n" );
    ob1=new( "/u/a/angel/item/ac.c" );
    ob1->move(this_object()); 
}


int catch_huntee( object who )
{
    tell_room( this_object(), 
      "快速龜看見 "+who->query("c_name")+" 大叫『你是壞人!』驚嚇地大叫\n"
    ,  ({ this_object(), who }) );
    tell_object( who, 
      "快速龜看見你之後，大叫『你是壞人!!!』迅速地逃開\n" 
    );
    return 1;
}
