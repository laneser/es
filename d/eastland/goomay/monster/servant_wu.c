#include <../goomay.h>
inherit Mob_special ;
int payed;
void create ()
{
        ::create();
        set_level(4);
        set_name( "Wu the servant", "王八老吳" );
        add ("id",({ "servant","wu"}));
        set_short( "王八老吳");
        set("unit","個");
        set_long(
@C_LONG
你看到一個猥瑣矮小的漢子，他約莫四五十歲，可是看起來卻更老，
營養不良的臉上還留著縱慾過度的痕跡，他提著一隻大茶壺，專門
服侍妓院中的嫖客和妓女。
C_LONG
);
        set("alignment",-350);
        set("wealth/silver",10);
	payed=0;
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set( "defense_type","berserk");
        set_c_verbs(({"%s用雙手向%s亂抓",
                      "%s用腳向%s亂踢",
                      "%s用頭向%s撞去"}));
       
        set( "inquiry", ([
                "jor" : "@@ask_jor"]));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"老吳用他的大茶壺灑出滾燙燙的熱水，一古腦兒淋在你身上，你感到一陣劇痛...\n\n");
set("c_room_msg","老吳用熱水淋向");
set("c_room_msg2", "，把他燙得哇哇叫 ... \n");
	
}

void init()
{
	::init();
        add_action( "tip_me", "pay");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "付誰？多少錢？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
               tell_object( this_player(),
                        "老吳賊賊的笑道: 大爺 ! 對不起，今年好像流行金幣耶。\n");
                return 1;
	}
	if (num<50)
	{
		tell_object(this_player(), 
                 "老吳說道: 大爺 ! 小的一條賤命難道只值這些錢嗎？\n" );
		return 1;
	}
	if (num>=50 && payed==0)
	{
                tell_object(this_player(), 
                 "老吳說道: 大爺 ! 小的這就知無不言啦 !! 請問吧 !!\n" );
		payed=1;
                return 1;
	}
        if (num>=500 && payed==1)
        {
                tell_object(this_player(), 
                "老吳說道: 好 !! 我這就帶你去 !! \n他帶著你穿過怡紅院的側門\n"
		"一路沿著圍牆直鑽，走著走著，他不知道在牆邊按了什麼機關，你\n"
		"突然一腳踏空，直摔了下去\n.\n.\n.\n.\n.\n.\n");
        this_player()->move_player( Goomay"in_yi_hong", "SNEAK" );
		remove();
                return 1;
	}

}

int ask_jor()
{
if (payed==1)
{
	tell_object(this_player(),
@C_WU
老吳道：「既然您已經知道我的事了，我想也用不著瞞您啦，沒錯 !! 
左無心確實躲在怡紅院內，他躲在一個很隱秘的地方，只有我知道，如
果你能再付給我衙門的賞金，我會考慮要不要帶你去 !! 不要懷疑啊 !!
這可是賣命的事，你不給自然有人會給。」
C_WU
);
        return 1;
}
else
{
tell_object(this_player(), 
	    "老吳笑道: 大爺 !! 您也是知道的，小的最近手頭上有點緊，嘴巴自然也鬆不下來嘍 !!\n" );
	return 1;
}
}
