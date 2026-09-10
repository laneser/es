#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("white turban", "白綸巾");
        add( "id", ({ "turban" }) );
        set_short( "白綸巾");
        set_long(@C_LONG
白綸巾是一般世俗人物最喜愛佩帶的頭帶了。 
C_LONG
        );
        set("unit","頂");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 30 );
        set( "value", ({ 60, "gold" }) );
}



