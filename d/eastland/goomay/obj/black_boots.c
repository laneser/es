#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name("black boots", "黑靴");
        add( "id", ({ "boots","boot" }) );
        set_short("a pair of black boots", "黑靴");
        set_long(
                "A pair of boots made of cloth  .\n",
"一雙沾滿泥巴的黑色靴子，聽說是阿丁老婆繡給他的，當阿丁清醒 \n" 
"時常常會抱著靴子痛哭... \n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set("material","leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 600, "silver" }) );
}
