#include "../hole.h"

inherit WEAPON;
void create() 
{
	set_name( "Baseball Bat","美津濃球棒" );
	add( "id",({ "bat" }) );
	set_short( "Baseball Bat","美津濃球棒" );
	set_long(@LONG
	棒球是蜥蜴人小孩最愛的休閒活動，所謂棒球
	就是拿一根棒子來打球，而你手上這根棒子就
	是用來打球的；不過好像也可以拿來打人吧 !
LONG
            );
	set( "unit","支" );
	set( "weight",9 );
	set( "value",({ 100,"silver" }) );
	setup_weapon( "blunt",8,5,15 );
	set( "no_sale",1 );
}
