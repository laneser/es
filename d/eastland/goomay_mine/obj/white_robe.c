#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white robe", "雲袍" );
	add( "id", ({ "robe", }) );
	set_short( "雲袍");
	set_long(@C_LONG
	一件潔白無暇的白色袍子，由袍子上所發出的聖潔光輝，使人覺得只要
	是配得上這袍子的人，絕對是一個善良的好人，對於邪惡的魔法也許有
	些許的保護能力．	
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 24 );
	set( "defense_bonus", 9 );
	set( "special_defense" ,
	      ([ "evil": 5 ]) );
	set( "value", ({ 2000, "silver" }) );
}
