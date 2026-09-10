#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing boy", "羽民小弟弟" );
	add( "id", ({ "boy" }) );
	set_short( "羽民小弟弟" );
	set_long(@C_LONG
一個居住在羽民村裡的小孩。他年約十一、二歲，頭上梳了兩個ㄚ髻，正快樂地在
這片草原上嬉戲玩耍，一對大眼睛骨溜溜地盯著你瞧，不時在你周圍打轉，活潑極
了。
C_LONG
        );
	set( "gender", "male" );
	set( "race","羽民" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
