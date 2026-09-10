#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("snake", "小草蛇" );
        set_short("snake", "小草蛇" );
        set_long(
@C_LONG
這是條小草蛇，從你的常識來判別，你知道這是無毒的
C_LONG
        );
        set( "unit", "條" );
        set( "alignment", -200 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set("chat_chance",5);
        set( "chat_output", ({
                "小草蛇在你的腳邊遊走。\n" }) );
        set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
        set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

