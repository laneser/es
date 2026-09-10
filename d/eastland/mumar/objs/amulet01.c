#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Golden Necklace","金龍項□");
        add("id",({"necklace"}) );
        set_short("金龍項□");
        set_long(
"這是一條用相當粗的金子打造成龍型的項□,看來應該值不少錢才是。\n"
        );
        set( "unit", "條" );
        set( "weight", 50 );
        set( "type", "misc" );
        set( "material", "light_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_denense", (["fire":10]));
        set( "value", ({ 2300, "silver" }) );
        set( "no_sale", 1 );
}
