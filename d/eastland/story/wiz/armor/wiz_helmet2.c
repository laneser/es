#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("medicine hat","藥師護頭");
        add( "id", ({ "hat" }) );
        set_short("藥師護頭");
        set_long(@C_LONG
一件用白麻做的類似山的形狀的頭帶。這頭帶上塗有防毒防酸的藥材，唯一的缺點
是不防火。
C_LONG
        );
        set( "unit","頂");
        set( "type", "head" );
        set( "material","healer");
        set( "armor_class",7 );
        set( "defense_bonus",4);
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set("special_defense",
             (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}



