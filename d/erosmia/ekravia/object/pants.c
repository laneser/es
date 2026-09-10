
#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black pants", "黑長褲" );
	add( "id", ({ "pants", "black pants" }) );
   set_short( "黑長褲" );
	set_long( @LONG
這是一件棉質的黑色長褲, 大多被用來搭配正式禮服。
LONG
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "weight", 20 );
	set( "value", ({ 300, "silver" }) );
}
