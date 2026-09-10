#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("rainbow cloth","七彩雲衣");
        add("id",({"cloth"}) );
        set_short("七彩雲衣");
	set_long(@C_LONG
這是用布做的衣服,上面七種顏色交輝相映,煞是好看。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 1500, "silver" }) );
}
