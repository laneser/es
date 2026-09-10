#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "goose", "白鵝" );
	set_short( "白鵝" );
	set_long(
		"這隻鵝正以一種優雅的姿勢漫步著。\n"
	);
	set("unit", "只" );
	set("alignment", 200);
	set_c_limbs( ({ "腳丫", "頭部", "身體", "翅膀" }) );
	set_c_verbs( ({ "%s張開翅膀往%s拍打", "%s用它的嘴巴啄%s" }) );
}
