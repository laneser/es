#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("silver pallium","銀灰補衲");
    add("id",({"cloth","pallium"}) );
    set_short("銀灰補衲");
	set_long(@C_LONG
這是一件看來很新的補衲, 用灰布織成的並滾上銀邊, 只有級位相
當高的和尚有資格穿著, 它長年在廟中被使用, 聞起來有一股上好
的薰香味 !
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
        set("material","monk");
	set( "type", "body" );
	set( "armor_class", 19 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1691, "silver" }) );
}
