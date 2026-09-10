#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing girl", "羽民小妹妹" );
	add( "id", ({ "girl" }) );
	set_short( "羽民小妹妹" );
	set_long(@C_LONG
一個居住在羽民村裡的小孩。她年約十一、二歲，頭上綁著一個馬尾辮子，一對烏
溜溜的大眼，模樣甚是可愛。小女孩正在和她的同伴追逐嬉戲，不時傳來歡樂的笑
聲。
C_LONG
        );
	set( "gender", "female" );
	set( "alignment", 100 );
        set( "race","羽民" );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
