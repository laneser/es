#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "wind belt", "束雲腰帶" );
        add( "id", ({ "wind","belt" }) );
        set_short( "束雲腰帶" );
        set_long(@C_LONG
束雲腰帶是由天然蠶絲編織而成的,上面繡有一大片浮雲因之而命名為束雲腰帶。
束雲腰帶是由震八方死去的妻子製成給他的, 對他而言等於無價之寶,雖然不乏識
貨的人問津,可是震八方怎麼也不肯割愛。       
C_LONG
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 150, "gold" }) );
}
