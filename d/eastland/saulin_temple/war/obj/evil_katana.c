
#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "evil katana", "妖刀" );
        set_short( "妖刀「村正」" );
        set_long(@C_LONG
這是一把長刃武士刀，雪亮的刀刃散發著妖異的紅光，相傳
這把刀已經成妖，喜歡吸收生物的血氣，不管是友是敵。
C_LONG
        );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 90 );
        set( "weapon_class", 36 );
	set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "bleeding", 10 );
        set( "value", ({ 2700, "silver" }) );
}
