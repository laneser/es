
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "maid", "婢女" );
        set_short("婢女");
        set("unit","個");
        set_long(
@C_LONG
    她是一位很可愛的小女孩，梳著三丫頭髻，一副什麼都不怕的樣子。
她正在堂前打掃，順便幫她美麗的女主人看守門戶，不過像她這樣年紀
的小女孩，一定很喜歡一些新奇的玩意兒。
C_LONG
);
        set ("gender", "female");
        set ("race", "human");
		set("no_attack",1);
}
void init()
{
        add_action( "kill_me", "kill");
}

int kill_me(string arg)
{
  if (arg=="maid")
	{
	tell_object(this_player(),
		"婢女生氣地道 ： 「喔 ～～好不要臉 !! 欺負我年紀小嗎？出去出去 !!」\n"
		"說著就把你推出門外。\n" 
		);
      this_player()->move_player( Goomay"rich_house", "SNEAK" );
        tell_room( Goomay"rich_house", 
         this_player()->query("c_name") + "被人從綠珠樓轟了出來。\n"
        ,this_player() );
        return 1;
	}
	else 
	this_player()->command("kill "+arg);

}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
那婢女接過珍珠戒指對光一看。她啐了你一口道：「這根本是假貨嘛 !! 
你花了多少冤枉錢買的？ 」她把戒指往地上一擲，瞧也不瞧一眼。
RING
	);
        command("drop "+name);
        return 1;
}
     tell_object(me,
@MISSION
那婢女接過珍珠對光一看，兩顆眼珠突然發出光芒。
她叫道：「這好像是真品呢 !! 讓我來好好鑑定鑑定 。」
說著她就不再理你了。
MISSION
	);
		item->remove();
		this_player()->set_temp("give_pearl",1);
        return 1;
}
