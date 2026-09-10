
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(1);
	ob->set_name( "stone frog", "石頭蛙" );
	ob->add( "id", ({ "frog" }) );
	ob->set_short( "石頭蛙" );
	ob->set_long(
	 "你看到一隻灰褐色的青蛙，身上有著石頭般紋路的皮膚，正不斷地
傳來「咯咯」的低沈叫聲。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", 500 );
	ob->set( "unbleeding", 1 );
	ob->set_perm_stat("str", 5);
	ob->set_c_verbs( ({ "%s用後腿往%s一踢" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腿部" }) );
}
