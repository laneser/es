
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Samurai＿short＿dagger", "武士短刃" );
        add( "id",({ "dagger" }) );
        set_short( "Samuria＿short＿dagger", "武士短刃" );
        set_long("this is a short dagger with great power .\n",
            "這是一把鋒利短小的匕首，雖然此匕首體積小但卻含有其大的破壞力\n"
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
        set( "type", "dagger" );
        set( "min_damage", 13 );
        set( "max_damage", 28 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
}


