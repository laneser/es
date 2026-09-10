#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spirit robe","靈力之袍" );
        add( "id", ({ "robe","cloth" }) );
        set_short( "靈力之袍" );
        set_long(
                "一件看起來破破爛爛的袍子，但卻有著相當不錯的防護力。\n"
        );
        set( "unit", "領" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 26 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 410, "silver" }) );
}
