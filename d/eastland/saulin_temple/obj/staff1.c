#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "we-tow staff", "韋陀杵");
        add ("id",({ "staff"}) );
        set_short("韋陀杵");
        set("unit", "把");
        set_long(@C_LONG
這是一把由千年紫檀木做成的禪杖，上面的雕工十分的精細，你一看就知道
這一定是某個師傅窮畢生的精力所完成的。同時這也是少林寺方丈的信物。
C_LONG
        );
        set("weapon_class", 30);
        set("type", "bo");
        set("min_damage", 20);
        set("max_damage", 40);
        set("weight", 220 );
        set("no_sale",1);
        set("value", ({ 2500, "silver" }) );
}
