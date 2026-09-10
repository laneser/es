#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("God Longsword","絕仙劍");
	add ("id",({ "longsword","sword","god" }) );
        set_short("絕仙劍");
	set_long(@C_LONG
絕仙劍乃為通天教主所擺設誅仙陣裡的四口寶劍之一。此劍倒懸門上, 發雷□動,
劍光一晃,任從他是萬劫神仙,也難逃得此難。 昔曾有贊,贊此寶劍:「非銅非鐵又
非鋼,曾在須彌山下藏。 不用陰陽顛倒煉,豈無水火淬鋒芒? 誅仙利,戮仙亡,陷仙
到處起紅光;絕仙變化無窮妙,大羅神仙血染裳。」
C_LONG
	);
	set( "unit", "口" );
        setup_weapon("longblade", 35,28,42);
	set( "weight", 150 );
	set( "no_sale", 1);
        set( "second", 1);
	set( "value", ({ 3410, "silver" }) );
        set("hit_func","my_damage");
}
