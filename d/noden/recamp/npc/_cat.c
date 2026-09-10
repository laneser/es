#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(3);
	ob->set_name( "big cat", "大懶貓" );
	ob->add( "id", ({ "cat","big cat" }) );
	ob->set_short( "大懶貓" );
	ob->set_long(
	 "你看到一隻巨大的懶貓，正躲在角落。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", -200 );
	ob->set_c_verbs( ({ "%s張開大嘴往%s腿上一咬" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腿部" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"大懶貓說:命苦呀! 抓不到老鼠還不夠? 大俠你還要我的命!!\n",
            "大懶貓說:大俠別殺我!! 我知道角落藏著的秘密 !!\n",
            "大懶貓說:死老鼠! 別偷笑! 待會而就換你遭殃啦!!\n"})) ;
}
