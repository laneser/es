#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("axe", "旋天斧");
	add( "id", ({ "axe" }) );
	set_short("An axe", "旋天斧");
	set_long(@AA
這把斧頭上面刻滿了奇怪的花紋，舞起來可以讓敵人頭昏眼花，天旋地
轉，露出致命的破綻．
AA
	);
	set( "unit", "把" );
	set( "weight", 250 );
	set( "weapon_class",37);
	set( "min_damage",21);
	set( "max_damage",41);
	set( "type","axe");
        set( "bleeding", 10 );
	set( "value", ({ 980, "silver" }) );
}
