
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "magic staff", "法杖");
        add ("id",({ "staff" }) );
        set_short( "法杖");
        set_long(
            "這是地精族所使用的武器，它並不鋒利而且沒有魔法的特殊攻擊，\n"
            "但是他的特殊材質使得其攻擊力有一定強度。 \n" );
        set( "weapon_class", 25 );
        set( "min_damage", 14);
        set( "unit","把");
        set( "max_damage", 20);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

