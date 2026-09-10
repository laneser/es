#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name( "sky lun", "梵天法輪");
        add( "id", ({ "shield", "lun" }) );
        set_short("梵天法輪");
        set_long(@C_LONG
法輪是一種佛法的具相, 具有防禦及攻擊雙重的效能。
不要相信你鑑定的結果, 梵天法輪是非常好又輕的防具。
C_LONG
		);
        set( "unit", "座"); 
        set( "type", "shield" );
        set( "armor_class", 8 );
	set("material","monk");
        set( "defense_bonus", 4 );
        set( "weight", 50 );
        set( "value", ({90, "gold" }) );
}
