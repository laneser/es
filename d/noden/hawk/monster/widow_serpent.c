#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "widow serpent", "寡婦蛇" );
	add( "id", ({ "serpent" }) );
	set_short( "寡婦蛇" );
	set_long(@CLONG
這是一種女人的臉，蟒蛇的身體，十分兇暴殘忍的一種怪物，她的叫聲
像女人哭泣的聲音，但是那並不表示她在傷心，而是表示她肚子餓了！
CLONG
	);
	set( "unit", "條" );
	set( "gender", "female" );
	set( "alignment", -1000 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 16 );
	set( "natural_max_damage1", 33 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "dodge", 80 );

	set( "killer", 1 );
	set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
	set_c_verbs( ({ "%s張開血盆大口，往%s咬去", "%s擺動尾巴，甩往%s" }) );
}
