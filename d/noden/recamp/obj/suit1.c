#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Magic suit", "魔法洋裝");
        add( "id", ({ "suit" }) );
        set_short("Magic suit", "魔法洋裝");
        set_long(@AAA
這是一件以特殊輕金屬打造而成的魔法洋裝，可展現出迷人的身材曲線。
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 10 );
        set( "defense_bonus", 10 );
        set("material","light_metal");
        set("special_defense",(["electric":10,"fire":10,"cold":10])) ;
        set( "weight", 100 );
        set( "value", ({ 1000, "silver" }) );
}
