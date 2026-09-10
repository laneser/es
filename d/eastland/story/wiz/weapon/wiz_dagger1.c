#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("golden needle","渡劫金針");
	add ("id",({ "needle","dagger"}) );
        set_short("渡劫金針");
	set_long(@C_LONG
這是一把純金打造的細針，既輕且薄，韌性奇佳，拿來針炙治病是最好不過了。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("dagger", 30,19,33);
        set( "special_things",1);
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}

