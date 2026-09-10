
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(2);
	ob->set_name( "mi rat", "米老鼠" );
	ob->add( "id", ({ "rat","mi rat" }) );
	ob->set_short( "米老鼠" );
	ob->set_long(
	 "你看到一隻灰褐色的米老鼠，正不斷地「吱吱」亂叫。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", -100 );
	ob->set_c_verbs( ({ "%s張開大嘴往%s腿上一咬" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腿部" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"米老鼠說:命苦呀! 老貓欺負還不夠? 大俠你還要我的命!!\n",
            "米老鼠說:死懶貓! 別偷笑! 待會而就換你遭殃啦!!\n"})) ;
}
