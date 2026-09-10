#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("God-killed Shortsword","誅仙劍");
	add ("id",({ "shortsword","sword","god-killed" }) );
        set_short("誅仙劍");
	set_long(@C_LONG
這是由通天教主所擺設的誅仙劍陣裡的一把武器,劍身透出一陣陣的藍光。據說,
姜子牙曾經敗在這把誅仙劍之下,可見得這把武器有多麼厲害。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("shortblade", 38,28,42);
	set( "weight", 100 );
	set( "no_sale", 1);
	set( "value", ({ 10, "silver" }) );
}

