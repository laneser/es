#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Amulet", "冰雪護符");
        add( "id", ({ "snow","amulet" }) );
        set_short("Snow Amulet", "冰雪護符");
        set_long(@AAA
這是一件雪白色的護身符，其上附有雪之精靈的祝福
AAA
        );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":10]));
        set( "weight", 10 );
        set( "no_sale",1);
        set( "value", ({ 880, "silver" }) );
}
