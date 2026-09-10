
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "evil dragon dagger", "孽龍寒匕" );
        add( "id",({ "dagger","dragon" }) );
        set_short( "孽龍寒匕" );
        set_long(@C_LONG
這是以孽龍恨天之血浸潤過的匕首，並將之浸泡在萬年寒泉中數百年，
故其鋒利無比，其上亦有閃爍著奇異的金屬光芒。
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 23 );
        set( "max_damage", 36 );
        set( "weight", 50 );
        set( "value", ({ 400, "gold" }) );
}

