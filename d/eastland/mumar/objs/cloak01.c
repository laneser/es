#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("asbestos net","石棉網");
        add("id",({"net","cloak"}) );
        set_short("石棉網");
        set_long(
"這是一件石棉網，你覺得穿上這玩意兒不會很舒服。\n"
        );
        set( "unit", "件" );
        set( "weight", 100 );
        set( "type", "cloak" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "value", ({ 1800, "silver" }) );
        set( "no_sale",1);
        set( "special_defense",(["fire":15]));
}
