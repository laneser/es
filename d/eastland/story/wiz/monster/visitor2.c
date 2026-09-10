#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "visitors", "一大群觀光旅客" );
	set_short( "一大群觀光旅客" );
	set_long(@C_LONG
這是從外地來這裡觀光的旅客，看他們盡情揮灑金錢的樣子，一個勝過一個，一個
又賽似一個，吵吵嚷嚷，不知是打那兒來，好像是暴發戶一般，令你頓生厭惡之感
。
C_LONG
        );
        set( "wealth/silver",300);
        set( "alignment",-1000);
        set( "unit","");
        set( "gender","neuter");
        set_natural_armor(75,0); 
        set_natural_weapon( 27,14,28 );
}
