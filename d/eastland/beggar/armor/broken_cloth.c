#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("broken cloth","鳩衣");
        add("id",({"cloth"}) );
        set_short("鳩衣");
	set_long(@C_LONG
這是一件破跛爛爛的衣服, 在這件衣服上面的結不下幾千個,又有一股汗臭傳了過
來, 真是一件標準的乞丐裝束。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set("special_defense",
	     (["fire":-10]) );
	set( "value", ({ 500, "silver" }) );
}
