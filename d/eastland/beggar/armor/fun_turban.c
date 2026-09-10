#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("sun helmet", "至陽頭帶");
        add( "id", ({ "helmet" }) );
        set_short( "至陽頭帶");
        set_long(@C_LONG
至陽頭帶是用一種特殊的布料,然後經過百年烈焰的□練而成的, 製成的機率可說
是千分之一。除此之外,還附有製造者渾厚的元陽內力, 所以用來防火系攻擊是最
好不過的一件東西了。
C_LONG
        );
        set("unit","頂");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class",7 );
        set( "defense_bonus", 5 );
        set( "weight", 40 );
        set( "value", ({ 60, "gold" }) );
        set("special_defense",
                     (["fire":5]) );
}



