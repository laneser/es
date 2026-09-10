#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long blue garb", "天藍色長袍" );
	add( "id", ({ "garb" }) );
	set_short( "a long blue garb", "天藍色長袍" );
	set_long(
		"You see a blue long garb.\n",
		"這是一件很普通的天藍色長袍，就像是一般掌櫃朝奉們常穿的那種。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 140, "silver" }) );
}
