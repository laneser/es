
#include <mudlib.h>
inherit MONSTER;

void create()  {
	::create();
	set_level(5);
	set_name("pig8");
	set("race","human");
	set("gender","male");
	set_short("The evil pig", "豬八戒");
	set_long(
"\n",
"豬八戒是色狼協會的守護神. 它有圓圓的身體, 大大的耳朵, 色眯眯的\n"+
"嘴臉. 並不時從嘴腳流出淫蕩的唾液! 讓你看了覺得十分舒服, 很想鼓\n"+
"起勇氣, 上前跟它抱抱!\n"
	);
	set("no_attack",1);
	set("chat_chance",5);
	set("chat_output",({
"Pig8 says to you with its EVIL looking face:Believe in me and you'll\n"+
"have a permanent life!\n",
"豬八戒色眯眯的對你說道：信我者得永生!\n"
	}));
}

void init()  {
	if ((int)this_player()->query("CWA") == 1) {
		write(can_read_chinese()?
"你大老遠就聽到色狼守護神豬八戒親切地對你說："+this_player()->query("c_cap_name")+"! 我的子民! 歡迎你回家!\n" :
"Welcome HOME! "+this_player()->query("cap_name")+"! My lovely child!\n");
		tell_room(environment(this_player()), ({
"Let's stand up to welcome "+this_player()->query("cap_name")+"'s coming\n",
"豬八戒興奮地說道：讓我們起立鼓掌歡迎色狼英雄"+this_player()->query("c_cap_name")+"的到來!\n"}),
		this_player());
	} else {
		write(can_read_chinese()?
"你還未踏進大廳, 就聽道豬八戒的聲音："+this_player()->query("c_cap_name")+"! 我注意你很久了! 像你這麼色的人應該趕快加入我們神聖的色狼協會!\n" :
"I've been watching you for a loooong time! "+this_player()->query("cap_name")+"! I think ppl\nas color as you better join us CWA ASAP!\n");
	}

}
