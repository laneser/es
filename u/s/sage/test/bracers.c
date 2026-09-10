#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "dragon bracers", "神龍護腕" );
        add( "id", ({ "bracers" }) );
        set_short( "神龍護腕" );
        set_long(@C_LONG
這是殺手門的鎮門之寶，相傳它能夠提升一個人的基本內功能力。
它看起來是由某種銀絲做成的，上面繡著一條黑色的龍。
C_LONG
        );
        set( "unit", "雙" );
        set( "type", "hands" );
        set( "no_sale", 1 );
        set( "armor_class", 1 );
        set( "extra_skills", (["inner-force":100]) );
        set("material","cloth");
        set( "weight", 1 );
        set( "value", ({ 10000000, "gold" }) );
}

