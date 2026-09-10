#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "coul", "大鐵桶");
        add ("id",({ "coul"}) );
        set_short("大鐵桶");
        set("unit", "對");
        set_long(@C_LONG
這是一對裝滿水的大鐵桶，因為鐵桶是用寒鐵所鑄，裡面的水都已經
結成冰了。
C_LONG
        );
        set("nosecond",1);
        set("weapon_class", 15);
        set("type","chain");                        
        set("min_damage", 10);
        set("max_damage", 15);
        set("weight", 30);
        set("value",({ 250, "silver"}));
}
