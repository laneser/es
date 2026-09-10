#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold legging","金護膝");
        add( "id", ({ "legging" }) );
        set_short("Gold legging", "金護膝");
        set_long(@AAA
這是一件用貴重金屬打造而成的金護膝，提供嚴密的保護。
AAA
        );
        set( "unit", "件"); 
        set( "type", "legs" );
        set( "armor_class", 5 );
        set("material","heavy_metal");
	set( "weight", 50 );
        set( "value", ({ 500, "silver" }) );
}
