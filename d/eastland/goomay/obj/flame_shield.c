#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name( "flame shield", "火焰盾");
        add( "id", ({ "shield" }) );
        set_short("a flame shield", "火焰盾");
        set_long(
           "This is a magic shield which made by element of fire .\n",
           "這是一面由火焰精華錘□而成的魔盾，據說它的魔法抗力遠遠超過一般的魔法盾。\n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","element");
        set( "weight", 150 );
        set( "no_sale",1);
        set("special_defense",(["cold":30, ]));
        set("extra_stats",(["dex":-1,"con":-2 ,]));
        set("extra_skills",(["shortblade":10,]));
        set( "value", ({ 350, "gold" }) );
}
