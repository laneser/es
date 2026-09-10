#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon chainmail","飛龍之鎧");
        add( "id", ({ "chainmail","dragon" }) );
        set_short( "dragon chainmail","飛龍之鎧" );
        set_long(@AAA
一個刻有飛龍圖案的鎧甲，具有超高的防禦力，是忍者葛拉的傳家之寶據說
其高防禦力是來至此鎧曾浸過龍血．
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 35 );
        set( "defense_bonus", 4 );
        set("material","element");
        set("extra_skills", ([ "dodge" : 5 ]) );
        set( "weight", 170 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver"
         }) );
}
