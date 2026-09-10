#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "totem shield", "圖騰盾" );
	add( "id", ({ "shield" }) );
	set_short( "圖騰盾" );
	set_long(@C_LONG
這面盾是用某種你從沒見過的奇特金屬製成的，上面畫滿了各種色彩鮮豔
的符文與圖形，在戰鬥中可以讓敵人心生畏懼。
C_LONG
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 7 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 180 );
	set( "value", ({ 1750, "silver" }) );
}
