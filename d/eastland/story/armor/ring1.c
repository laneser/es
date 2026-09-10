inherit ARMOR;

void create()
{
        set_name("buddha ring","□戒");
        add( "id", ({ "ring" }) );
        set_short( "□戒");
        set_long(@C_LONG
一隻鑲著□字符號的戒指，戒指上不時閃爍著七彩虹光。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 7 );
        set( "weight", 5 );
        set( "value", ({ 600, "silver" }) );
}



