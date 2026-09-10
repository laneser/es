#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("damo pallium","達摩架裟");
    add("id",({"cloth","pallium"}) );
    set_short("達摩架裟");
	set_long(@C_LONG
這是一件看來很破舊的架裟,相傳是當年達摩老祖所留下來的,只有
級位相當高的和尚有資格穿著,相傳它附有達摩老祖的佛法,能幫你
躲過魔孽。
C_LONG
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","monk");
	set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
}
