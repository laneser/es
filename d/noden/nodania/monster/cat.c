#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "yellow cat", "大黃貓" );
	add( "id", ({ "cat" }) );
	set_short( "大黃貓" );
	set_long(
		"一隻全身黃毛的大貓，它看起來很兇，像是一隻小獅子。\n"
	);
	set_c_limbs( ({ "後腿", "前腳", "頭部", "尾巴", "身體" }) );
	set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
	set_skill( "dodge", 10 );
}
