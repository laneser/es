#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black eye patch", "黑眼罩" );
	add( "id", ({ "eye patch", "patch" }) );
   set_short( "黑眼罩" );
	set_long(
		"一副看起來很滑稽的黑色眼罩，這副眼罩的主人一定是認為帶著這樣的眼罩\n"
		"看起來很酷。\n"
	);
	set( "unit", "副" );
	set( "type", "head" );
	set( "material","leather");
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense",(["electric":1,"clod":1]) );
	set( "value", ({ 250, "silver" }) );
	set( "weight", 15 );
}
