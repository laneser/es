#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sword", "長劍" );
        set_short( "雪魄劍" );
	set_long(@CLONG
這是耶拉曼王室家傳的寶劍，也就是數百年前耶拉曼大帝征服整個諾頓
大陸時所使用的佩劍。你可以看到劍柄上刻著象徵耶拉曼王室的獅鷲獸
圖紋，劍刃上的寒氣使你幾乎開始發抖。
CLONG
       	        );
	set( "unit", "把" );
	set( "weapon_class", 44 );
	set( "type", "longblade" );
	set( "min_damage", 27 );
	set( "max_damage", 50 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 7000, "gold" }) );
	set( "no_sale", 1 );
}
