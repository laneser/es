#include "mudlib.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "little boy", "童子" );
        add ("id",({ "boy"}));
        set_short( "童子");
        set("unit","位");
        set_long("",
@C_LONG
他是一個十歲大的孩子，正沒精打彩的坐在藥爐邊守著爐火。手中的扇子
偶而會晃一下, 又停了。看他無聊的樣子, 可能希望有人陪他聊聊吧。
C_LONG
);
        set("alignment",0);
        set("wealth/silver",15);
        set_perm_stat("str",10);
        set_perm_stat("dex",8);
        set_perm_stat("kar",8); 
        set_natural_weapon(5,3,6);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
	set("defense_type","dodge");
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
	 set( "inquiry" , ([
		"wang" : "師父在書房歇著, 您有事嗎?",
		"herb" : "珍貴的藥材通常都很難找..上次去採藥還差點被毒蛇咬死。\n",
		"oven" : "師父煉的藥都是用這個爐子煉的。\n", 
		"painting" : "@@ask_painting",
	]));
       
}

void ask_painting(object who)
{
	tell_object(who, 
"你是說師父牆上掛的畫嗎? 自從來到這裡後, 師父常常對這那畫發呆。有一次我\n"
"走進書房裡, 師父不在, 可是過一會兒卻從書房走出來 ... 好奇怪喔 \n"
	);
}


