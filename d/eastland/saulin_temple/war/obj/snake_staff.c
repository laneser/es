
#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("staff of snake","蛇杖");
        add("id",({"staff",}) );
	set_short("蛇杖");
	set_long(@C_LONG
這是一把漆黑的鋼杖，鑄成惡魔面孔的杖頭上正有兩隻五彩斑斕的
怪蛇上下地遊走著，不時昂首吐信，顯得詭異非凡。
C_LONG
               );

        set( "unit", "把" );
        set( "weapon_class", 24 );
	set("type","blunt");
        set( "min_damage", 15 );
        set( "max_damage", 30 );
	set( "weight", 180 );
        set( "value", ({ 170, "gold" }) );
}
