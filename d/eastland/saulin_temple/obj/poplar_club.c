#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "poplar club", "柳木棍");
        add ("id",({ "club"}) );
        set_short("柳木棍");
        set("unit", "把");
        set_long(@C_LONG
這把棍子是利用柳木所製成，充份利用到柳木的彈性，因此在戰鬥中的命
中率比普通木棍還高。
C_LONG
        );
        set( "weapon_class", 19 );
        set( "type", "bo" );                        
        set( "min_damage", 10);
        set( "max_damage", 16);
        set( "weight", 55 );
        set( "value", ({ 280, "silver" }) );
}
