#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "copper club", "熟銅棍");
        add ("id",({ "club"}) );
        set_short("熟銅棍");
        set("unit", "把");
        set_long( @C_LONG
這是一把由熟銅鑄成的棍子，是少林武僧最喜歡用的武器之一。
C_LONG
        );
        set( "weapon_class", 15 );
        set( "type", "bo" );                        
        set( "min_damage", 12);
        set( "max_damage", 18);
        set( "weight", 100 );
        set( "value", ({ 380, "silver" }) );
}
