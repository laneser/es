#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("white lead ringmail", "白鉛環甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "白鉛環甲");
        set_long(
                "這是一件由白鉛製的環甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal"); 
        set( "armor_class", 28 );
        set( "defense_bonus", 3 );
        set( "weight", 270 );
        set( "value", ({ 150, "gold" }) );
}






