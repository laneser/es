#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name( "lan-hwa lun", "蓮華法輪");
        add( "id", ({ "shield","lun" }) );
        set_short("蓮華法輪");
        set_long(@C_LONG
法輪是一種佛法的具相, 具有防禦及攻擊雙重的效果, 蓮華法輪是
蓮華部觀世音座下之法器, 平時可當做盾牌使用, 降魔消障。        
C_LONG
		);
        set( "unit", "座"); 
        set( "type", "shield" );
        set( "material", "monk" );
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set( "weight", 110 );
        set( "value", ({ 120, "gold" }) );
}
