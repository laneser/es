
#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("shadow dagger","幻影匕首");
       add("id",({"dagger",}) );
       set_short("幻影匕首");
       set_long(@C_LONG
這是一把從刀刃到刀柄通體烏黑的匕首，通常被殺手用來進行隱秘
的暗殺行動。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 19 );
	set("type","dagger");
        set( "min_damage", 12 );
	set( "max_damage", 20 );
        set( "weight", 34 );
        set( "value", ({ 450 , "silver" }) );
}