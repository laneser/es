#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Fish Scale Tail","魚鱗尾甲" );
	add( "id", ({ "tail" }) );
	set_short( "魚鱗尾甲" );
	set_long(@LONG
	一副用地下洞穴水底的紅龍的鱗片配合蠶絲編
	成的尾甲，比一般金屬製的尾甲輕多了。
LONG
           );
	set( "unit","副" );
	set( "weight",50 );
	set( "type","tail" );
	set( "material","cloth" );
	set( "armor_class",8 );
	set( "defense_bonus",2 );
	set( "value",({ 680,"silver" }) );
}
