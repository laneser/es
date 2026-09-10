#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "prisoner", "逃犯" );
	add( "id", ({ "man" }) );
	set_short( "逃犯" );
	set_long(
		"他是一個衣不蔽體的可憐人，臉上帶著濃重的驚恐神情，好像正在躲避什麼。\n"+
		"你仔細的看他，咦 !! 他不是那個逃犯黃二嗎？\n"
	);
        set("unit","個");
        set( "inquiry", ([ "jail" : 
@JAIL
我是從鎮上的牢裡逃出來的，我真的是冤枉的 !! 求求你不要再把我
抓回去 !! 我們在床底下挖了一條地道，本來要通到城外的，沒想到卻通到一個
很大的院落，我也不知道那是哪裡，只聽見有人說著什麼月神、宮殿的，後來下
起大雨，地道塌了，我趁亂逃了出來，就一直躲在這裡。
我真的是無辜的，請你不要和別人一樣冤枉我。
JAIL
, "jor" : 
@PARTNER
左無心？你是說那個江洋大盜嗎？我根本不認識他，他也不管我的死
活，一出地道就把我一個人丟下了，不過他因為被刑求，所以雙腿不怎麼靈活，
要不是需要我扶他，他根本不會理我。他曾經問我鎮上最好的醫生是誰，我想他
可能去醫腿了 !! 我把我知道的都告訴你了，求求你饒了我吧 !!
PARTNER
]));
        set( "gender", "male" );
        set( "race", "human" );
        set_natural_armor( 40, 10 );
	set_natural_weapon(11,6,14);

	set( "chat_chance", 20 );
        set ("chat_output",({
                "那人哀求道：「求求你不要把我抓回牢(jail)裡去 !!」。\n",
	}) );
#include <replace_mob.h>
}
