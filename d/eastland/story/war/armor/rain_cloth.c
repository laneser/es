#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Raingod's robe","雨師之袍");
        add("id",({"robe"}) );
        set_short("雨師之袍");
	set_long(@C_LONG
一件透明薄如蟬翼的衣服，但卻堅韌無比，令人無法輕易撕開它。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "special_defense",(["cold":-20,"magic":30]));
	set( "value", ({ 1200, "silver" }) );
}
