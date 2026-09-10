#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's cloth","蚩尤戰袍");
        add("id",({"cloth"}) );
        set_short("蚩尤戰袍");
	set_long(@C_LONG
一件用布料縫製而成的護具，上面沾滿了許多血漬，前面還繡有一個紅色的大骷髏
頭。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set( "material","cloth");
	set( "armor_class",20);
	set( "defense_bonus", 4 );
	set( "value", ({ 1000, "silver" }) );
}
