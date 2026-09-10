#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("Green bracelet", "綠玉鐲子");
        add( "id", ({"bracelet" }) );
        set_short("@@looks");
        set_long(
                "這是一個淡綠色的翠玉鐲子，隱約流動著淺淺的光芒。\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "material", "element" );
        set( "defense_bonus",4 );
        set( "armor_class",4 );
        set( "weight", 20 );
        set( "value", ({ 123, "gold" }) );
        set( "special_defense", ([ "none" : 5 ]) );
        set( "no_sale",1);
}

string looks()
{
	return set_color("綠玉鐲子","GRN");
}