#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Plate","戰神鎧甲" );
	add( "id", ({ "plate" }) );
	set_short( "戰神鎧甲" );
	set_long(@LONG
	這是蜥蜴人自古代流傳至今的戰甲。這件戰甲
	只有蜥蜴人領袖才有資格穿，因為能當上蜥蜴
	人領袖的人，必定是個驍勇善戰的武士。
LONG
           );
	set( "unit","件" );
	set( "weight",130 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",8 );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
