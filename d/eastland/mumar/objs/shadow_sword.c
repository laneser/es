#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "shadow sword", "影劍" );
        add( "id", ({ "sword" }) );
        set_short( "影劍" );
        set_long(
                "這是一把暗赤色的長劍，凹凸不平的劍身似有點點斑影，故名。\n" );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 120 );
        set( "weapon_class", 23 );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "value", ({ 500, "silver" }) );
}
