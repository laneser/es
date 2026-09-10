#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "bloody claws", "血爪" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "血爪" );
        set_long(@C_LONG
這是一雙百□精鋼製成的鋼爪，與一般鐵爪不同的是它只有兩片爪刃，
可是泛著血紅色光芒的爪身卻更長，簡直跟兩把短劍沒什麼不同。
C_LONG
        );
        set( "unit", "雙" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 2970, "silver" }) );
        set_c_verbs( ({ "用%s往%s一劃", "%s劃出一道血紅色的閃光，掃過%s",
                "的%s「嘶」的一聲，往%s劃去", }) );
}
