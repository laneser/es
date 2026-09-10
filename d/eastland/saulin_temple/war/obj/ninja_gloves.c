
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja gloves", "忍者手套" );
        add( "id", ({ "gloves" }) );
        set_short( "忍者手套" );
        set_long(@C_LONG
這是一雙忍者專用的黑色皮手套，不起眼的外表下，卻有著超乎
平常的附著力，使得戴上它的人能在任何平滑的牆壁、屋頂來去
自如，不過看起來相當重。
C_LONG
        );
        set( "unit", "雙" );
        set( "type", "hands" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "weight", 80 );	
	set( "value", ({ 950, "silver" }) );
}
