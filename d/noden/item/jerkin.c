#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "leather jerkin", "皮製短衣" );
	add( "id", ({ "jerkin" }) );
   set_short( "皮製短衣" );
	set_long(
		"這件皮製短衣做得相當細心，接縫處都用較粗的皮繩綁緊，你發現"
		"短衣的口袋上還用粉紅色的絲線繡著「黛姆」的字樣。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 7 );
	set( "weight", 90 );
	set( "value", ({ 25, "silver" }) );
}
