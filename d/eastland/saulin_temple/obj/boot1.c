#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "天帝雲鞋");
        add( "id", ({ "boots","boot" }) );
        set_short("天帝雲鞋");
        set_long(@C_LONG
雲遊僧穿之鞋子稱為雲鞋, 即僧鞋也。
這是玉皇大帝賜給太上老君的鞋子, 相傳它雖然重但防禦力驚人。
C_LONG
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
