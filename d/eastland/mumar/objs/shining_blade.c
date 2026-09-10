#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "shining blade", "光刀" );
        add( "id", ({ "blade" }) );
        set_short( "光刀" );
        set_long(
                "這是一把散發著寒光的長刀。\n" );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 120 );
        set( "weapon_class", 23 );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "value", ({ 500, "silver" }) );
}
