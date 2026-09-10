#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "large shield", "大型盾" );
	add( "id", ({ "shield" }) );
	set_short( "大型盾" );
	set_long(
		"這個盾牌又大又厚，如果你熟悉用盾阻擋敵人的方法，這會是個不錯的選擇。\n"
	);
	set( "unit", "面" );
	set( "weight", 160 );
	set( "type", "shield" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 8 );
	set( "value", ({ 440, "silver" }) );
}
