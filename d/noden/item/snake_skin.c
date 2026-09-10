#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snake skin", "蛇皮覆甲" );
	add( "id", ({ "skin" }) );
   set_short( "蛇皮覆甲" );
	set_long(
		"這是一副用蛇皮做成的奇怪護甲，看起來是為有尾巴的人設計的。\n"
	);
	set( "unit", "副" );
	set( "type", "tail" );
	set( "material", "leather");
	set( "armor_class", 3 );
	set( "weight", 60 );
	set( "value", ({ 40, "silver" }) );
}
