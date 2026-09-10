#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Purple gloves","渲紫手套" );
        add( "id", ({ "gloves" }) );
        set_short( "渲紫手套" );
        set_long(
		"這是一雙罕見的木製手套，上面渲染了美麗的紫色花紋。\n"
        );
        set( "unit", "雙" );
	set("material","wood");
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "weight", 50 );
        set( "value", ({ 510, "silver" }) );
}
