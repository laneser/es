#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black hat", "黑色高帽" );
	add( "id", ({ "hat" }) );
   set_short( "黑色高帽子" );
	set_long(
		"這頂黑色、圓筒狀的高帽子一向是魔術師們的註冊商標。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 5 );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
}
