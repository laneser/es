#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's shield","地獄之盾");
        add("id",({"shield"}) );
        set_short("地獄之盾");
	set_long(@C_LONG
一件用布料縫製而成的盾牌，上面沾滿了許多血漬和刀斫的痕跡。
C_LONG	         );
	set( "unit", "面" );
	set( "weight",70 );
	set( "type", "shield" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
