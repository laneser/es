
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "willow club", "白楊棍");
        add ("id",({ "club"}) );
        set_short("白楊棍");
        set("unit", "把");
        set_long(@C_LONG
這把白楊棍是利用白楊質輕的特性製成的，是初學棍法的人的最佳選擇。
C_LONG
        );
        set( "weapon_class", 11 );
        set( "type", "bo" );                        
        set( "min_damage", 8);
        set( "max_damage", 14);
        set( "weight", 45 );
        set( "value", ({ 180, "silver" }) );
}
