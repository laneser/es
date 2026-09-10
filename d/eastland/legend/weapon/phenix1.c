#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("phenix longsword","鳳凰長刃");
	add ("id",({ "sword","longsword" }) );
        set_short("鳳凰長刃");
	set_long(@C_LONG
一把通體極薄的銀製武器，拿在手上幾乎感覺不到它的重量，這對於一個武林高手
而言可說是兵器上最好的選擇。鳳凰長刃因劍柄上刻有一隻鳳凰而命名，雕工精緻
，據說在實戰時，隱隱約約會有一隻兇惡的火鳳凰盤旋而上，可以給敵人不錯的恫
赫作用。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("longblade", 25,20,35);
	set( "weight", 70 );
	set( "no_sale", 1);
	set( "value", ({ 1730, "silver" }) );
}

