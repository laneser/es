#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("ice-ghost","冰精");
	add ("id",({ "dagger","ghost","ice"}) );
        set_short("冰精");
	set_long(@C_LONG
這是一塊千年寒冰的精華，雖然渾身圓鈍尚未加以琢磨，但它寒氣逼人，寶光透頂
，是塊璞玉。  
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("dagger", 20,13,20);
        set( "special_things",1);
	set( "weight", 50 );
	set( "value", ({ 1000, "silver" }) );
}

