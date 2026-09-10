#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("moon cloak", "元陰鬥蓬");
        add( "id", ({ "cloak" }) );
        set_short( "元陰鬥蓬");
        set_long(@C_LONG
這是一件頗大的鬥蓬。元陰鬥蓬是多年放在千年寒冰之下而製成的,在一萬件之中
只可能有一件, 可說是珍貴無比。這件鬥蓬上還附有製造者的陰寒內力,用來防冰
系攻擊是最好不過的一件東西了。
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus",6 );
        set("special_defense",(["cold":5]) );
        set( "weight", 50 );
        set( "value", ({ 110, "gold" }) );
}



