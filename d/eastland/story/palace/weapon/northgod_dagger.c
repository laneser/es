#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Crystal dagger","水晶匕首");
        add ("id", ({"dagger" }) );
        set_short("水晶匕首");
        set_long(@LONG
一把水晶製成的匕首，通體晶瑩透明，微微閃著白光。
LONG);
        set("type", "dagger");
        set("unit","把");
        set("weapon_class",25);
        set("min_damage", 14 );
        set("max_damage", 28);
        set("weight", 50);
        set("value", ({ 2000, "silver" }) );
}
