#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snake platemail", "盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "蛇盔甲" );
	set_long( @C_LONG
之所以被稱為蛇甲, 乃因為這鎧甲是由數千只墨綠色的小蛇製成.
這些蛇不知用甚麼金屬打造的, 遍體閃著綠光, 眼睛射出暗暗的紅
光, 你甚至懷疑那是活的.
C_LONG
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 30 );
	set( "defense_bonus", 3);
	set( "special_defense",
	     ([ "fire":3, "acid":5, "poison":5, "electric":-6 ]) );
	set( "weight", 400 );
	set( "no_sale", 1);
	set( "value", ({ 8100, "silver" }) );
}
