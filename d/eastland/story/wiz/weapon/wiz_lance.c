#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("king lance","霸王槍");
	add ("id",({ "lance"}) );
        set_short("霸王槍");
	set_long(@C_LONG
霸王槍是「巫羅王」慣用的一把武器，是天帝因功賞賜給他的，對他而言，愛逾性
命。近來戰禍不起，「巫羅王」已經很少使用這把武器了，但它本身的威力還是存
在的。
C_LONG
	);
	set( "unit", "把" );
        set( "nosecond", 1 );
        setup_weapon("jousting", 35,10,30);
	set("no_sale",1);
	set( "weight", 250 );
	set( "value", ({ 20000, "silver" }) );
}

