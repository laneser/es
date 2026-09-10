#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "katana", "螺旋刃" );
        set_short( "螺旋刃" );
	set_long(@C_LONG
這是一把黑月最喜愛用的武器, 刃身呈螺旋狀而且周圍極其鋒利,一不小心被它的
劍風掃到就非死即傷, 又因為拿在手上很輕幾乎忘了它的存在,所以最適合殺手型
的戰士用的。 
C_LONG	
	);
	set( "unit", "把" );
	set( "weight", 40 );
	setup_weapon("longblade",25,15,20);
	set( "value", ({ 1200, "silver" }) );
}

