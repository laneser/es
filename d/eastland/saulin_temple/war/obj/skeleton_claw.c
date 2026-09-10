#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "skeleton claws", "白骨爪" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "白骨爪" );
        set_long(
                "這是一雙泛著白色光芒的爪子，泛著絲絲的寒氣。\n"
        );
        set( "unit", "雙" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 970, "silver" }) );
        set_c_verbs( ({ "用%s往%s一抓", "%s劃出一道青白色的閃光，掃過%s",
                "的%s「嘶」的一聲，往%s劃去" }) );
}
