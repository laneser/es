#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "dirty shirt", "髒襯衫" );
	add( "id", ({ "shirt", }) );
	set_short("髒襯衫");
	set_long( @C_LONG
    一件用普通的布織成的襯衫, 又髒又臭, 不知多久沒洗了。
C_LONG
	);
	set( "unit", "件" );
        set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "value", ({ 10, "silver" }) );
}
