#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Saiyada shield", "賽亞達之盾");
        add( "id", ({ "shield" }) );
        set_short( "賽亞達之盾" );
        set_long(
@C_LONG
這是仿自傳說中的戰士－賽亞達所擁有的盾牌，而由邪術師奇姆所
打造的複製品，它的形狀為一細長的綾型，並在邊緣有雕許多的咒
文，能有效提攻魔法防禦。
C_LONG
        );
        set( "unit", "面");
        set( "type", "shield" );
        set( "material", "light_metal" );
   set( "armor_class",9);
        set( "defense_bonus", 5 );
        set( "special_defense",
          ([ "poison":15, "fire":12, "cold":-10 ]) );
         set( "weight", 100 );
        set( "value", ({ 1300, "silver" }) );
        set( "no_sale", 1);
}
