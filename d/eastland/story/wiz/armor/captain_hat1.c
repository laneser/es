#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("policeman's hat","麻紗帽");
        add( "id", ({ "hat" }) );
        set_short( "麻紗帽");
        set_long(@C_LONG
一頂用紡著麻布和紗料製成的黑色帽子，它的形狀有點像鴨舌帽，上面還繡著「夏
侯忍」三個漆金篆字。
C_LONG
        );
        set( "unit","頂");
        set( "type", "head" );
        set( "material","cloth");
        set( "armor_class",7 );
        set( "defense_bonus",1);
        set( "weight", 50 );
        set( "value", ({ 1500, "silver" }) );
}



