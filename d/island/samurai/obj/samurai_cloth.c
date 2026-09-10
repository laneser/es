#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_clothes ", "武士之服 ");
        add( "id", ({ "clothes","cloth" }) );
        set_short("samurai_clothes ", "武士之服 ");
        set_long(@AAA
這是武士們戰鬥時穿的輕便戰鬥服,雖然很輕但卻有奇佳的防護力
據說其秘密在於此衣服曾受過高級牧師的祝福
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 5 );
        set("material","element");
        set( "weight", 120 );
        set("special_defense",(["energy":5, ]));
        set( "value", ({ 900, "silver" }) );
}
