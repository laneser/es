#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Helmet","戰神頭盔" );
	add( "id", ({ "helmet" }) );
	set_short( "戰神頭盔" );
	set_long(@LONG
	這頭盔和戰神鎧甲剛好是一套，它是用一種質
	料較輕的金屬做成的，能確實保護頭部。
LONG
           );
	set( "unit","頂" );
	set( "weight",45 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",2 );
	set( "value",({ 1500,"silver" }) );
//	set( "no_sale",1 );
}
