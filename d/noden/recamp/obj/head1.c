#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gold head","貴重頭飾");
        add( "id", ({ "head" }) );
        set_short("Gold head", "貴重頭飾");
        set_long(@AAA
這是一件用貴重金屬打造而成的頭帶，提供嚴密的保護。
AAA
        );
        set( "unit", "件"); 
        set( "type", "head" );
        set( "armor_class", 10 );
        set("material","heavy_metal");
	set( "weight", 35 );
        set( "value", ({ 1000, "silver" }) );
}
