#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Thunder Cloak", "雷電披風");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "雷電披風");
        set_long(@AAA
這是一件附有雷電精靈力量的披風
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 5);
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["electric":5])) ;
	set( "weight", 15 );
        set( "value", ({ 500, "silver" }) );
}
