#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "天帝雲鞋");
        add( "id", ({ "boots","boot" }) );
        set_short("a pair of cloud boots", "天帝雲鞋");
        set_long(
"A pair of boots made of clouds  .\n",
"雲遊僧穿之鞋子稱為雲鞋, 即僧鞋也。\n"
"這是玉皇大帝賜給太上老君的鞋子, 相傳它雖然重但防禦力驚人。\n"
        );
        set("material","cloth");
        set( "unit", "雙");
        set( "type", "feet" );
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 120 );
        set( "value", ({ 2450, "silver" }) );
        set( "no_sale", 1 );
}
