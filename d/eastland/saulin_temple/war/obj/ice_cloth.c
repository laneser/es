
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("iceworm cloth","冰蠶衣");
        add("id",({"cloth"}) );
         set_short("冰蠶衣");
        set_long(@C_LONG
這是一件用北極冰蠶絲做成的衣服，除了有冰蠶絲強韌的彈力外，更
受過陰魔的加持，防禦力非同小可。
C_LONG
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 25 );
	set( "defense_bonus", 6 );
        set( "special_defense", ([ "ice" :8, "divine":-10 ]) );
        set( "value", ({ 318, "gold" }) );
}
