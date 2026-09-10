
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "east_feather_blade", "東方片羽劍" );
        add( "id",({ "blade","sword" }) );
        set_short( "east＿feather＿blade", "東方片羽劍" );
        set_long(@AAA
這是一把鋒利的長劍，是武士團的制式武器
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 22 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}



