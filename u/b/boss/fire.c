#include <mudlib.h>
#include <ansi.h>
inherit WEAPON;

void create()
{
        set_name( "wand", ""+HIR"烈火之杖"+NOR"" );
        add( "id", ({ "wand" }) );
        set_short( "烈火杖" );
        set_long(@CLONG
這是一把烈火杖，一種普通等級不錯的武器。
CLONG
                );
        set( "unit", "把" );
        set( "type", "wand" );
        set( "weapon_class", 10 );
        set( "min_damage", 5 );
        set( "max_damage", 10 );
        set( "power_on", 1);
        set( "weight", 40 );
        set( "value", ({ 500, "silver" }) );

        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "fire" );
        set( "special_damage", 15 );
        set( "special_c_msg", ""+HIR"冒出烈火發出無熱量"+NOR"" );
}
