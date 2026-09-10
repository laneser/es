#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai mark", "武士紋章 ");
        add( "id", ({ "samurai","mark","amulet"}) );
        set_short("samurai mark", "武士紋章");
        set_long(@AAA
           一個代表武士身分地位的紋章，只有對武士有重大功勞的人
           才能擁有此物
AAA
   );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set("material","element");
        set( "weight", 70 );
        set( "no_sale",1);
        set( "value", ({ 800, "silver" }) );
}
