#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blue battle armor", "青衣戰甲" );
	add( "id", ({ "battle armor", "armor" }) );
	set_short( "青衣戰甲" );
	set_long(@C_LONG
這是一件巧匠設計的戰甲，若嵐宮禁衛軍的制式護甲分為青、紅、白
、黑四種，分別發給四種品級的武官。
C_LONG
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "weight", 240 );
	set( "armor_class", 24 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1500, "silver" }) );
}
