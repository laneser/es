
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven staff", "精靈杖");
        add ("id",({ "staff" }) );
        set_short( "精靈杖" );
        set_long(
            "這是精靈長老所使用的武器，雖然它並不鋒利而且沒有魔法的特殊攻擊\n"
            "但由於是採集五金的精華，加以淬冶而成的武器，故堅硬異常是不錯的\n"
            "攻擊武器。 \n" );
        set( "weapon_class", 20 );
        set( "min_damage", 10);
        set( "unit","把");
        set( "max_damage", 18);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

