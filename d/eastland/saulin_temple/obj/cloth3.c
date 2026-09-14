#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wen-su robe", "文殊褋衣" );
	add( "id", ({ "robe" }) );
	set_short( "文殊褋衣" );
	set_long(
		"褋衣是祭祀神佛時所穿的衣服。文殊褋衣是祭拜文殊菩薩時穿的長袍。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "armor_class", 20 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "weight", 100 );
	set( "value", ({ 987, "silver" }) );
}
