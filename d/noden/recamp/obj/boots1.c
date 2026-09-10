#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "peg boots","釘鞋");
        add( "id", ({ "boots" }) );
        set_short("Peg boots", "釘鞋");
        set_long(@AAA
這是一雙釘鞋。
AAA
        );
        set( "unit", "雙"); 
        set( "type", "feet" );
        set( "armor_class", 3 );
        set("material","light_metal");
	set( "weight", 32 );
        set( "value", ({ 100, "silver" }) );
}
