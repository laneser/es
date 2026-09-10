#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "boy", "小男孩" );
	set_short( "小男孩" );
	set_long(@C_LONG
一個居住在「巫咸城」裡的小孩。他年約七、八歲，頭上梳了兩個ㄚ髻，一對大眼
睛骨溜溜地正圍在一團遊戲，活潑極了。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(25,0); 
        set_natural_weapon( 7,1,3 );
}
