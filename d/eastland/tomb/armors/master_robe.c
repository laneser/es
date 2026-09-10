#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "archmaster robe", "大國師袍" );
	add( "id", ({ "robe", }) );
	set_short( "大國師袍");
	set_long( 
@C_LONG
這是東方皇帝賜給大國師的長袍，據說是用古時海外某國所進貢的奇異衣料
所製成，有股暗暗的光芒。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 55 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 38 );
	set( "defense_bonus", 5 );
	set( "special_defense" ,
	      ([ "all": 20, "none":10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
