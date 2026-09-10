#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name( "king-kong-po-lo lun", "金剛波羅法輪");
    add( "id", ({ "shield","lun" }) );
    set_short("金剛波羅法輪");
    set_long(@C_LONG
法輪是一種佛法的具相,具有防禦及攻擊雙重的效能... 
金剛波羅法輪是少林幾代傳下的法器,平時可當做盾牌使
用,防禦力超強。
C_LONG
	);
    set( "unit", "座"); 
    set( "type", "shield" );
    set( "armor_class", 10 );
	set("material","monk");
    set( "defense_bonus", 6 );
    set( "weight", 110 );
    set( "value", ({ 150, "gold" }) );
    set( "no_sale", 1 );
}
