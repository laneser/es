#include <mudlib.h>

inherit ARMOR;
void create()
{
        set_name( "Kepi","軍帽" );
        add( "id",({ "kepi" }) );
        set_short( "軍帽" );
	set_long( @LONG
	一頂平凡的軍帽。
LONG
		);
        set( "unit","頂" );
        set( "type","head" );
        set( "material","cloth" );
        set( "armor_class",4 );
        set( "defense_bonus",2 );
	set( "weight",30 );
	set( "value",({ 320,"silver" }) );
}

