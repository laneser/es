#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "wolf", "暴狼" );
	set_short( "巴斯格的寵物--暴狼" );
	set_long(
		"你看到一隻非常巨大且兇惡的暴狼，對著你張牙舞爪。\n"
	);
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set_skill( "dodge", 70 );

	set( "unit", "只" );
        set_natural_armor(60,25);
	set_natural_weapon( 15, 10, 20 );

	set_c_verbs( ({ "%s用前爪撲向%s", "%s張開滿口利齒的嘴，往%s咬去" }) );
	set_c_limbs( ({ "頭部", "身體", "尾巴", "腿部" }) );
#include "../replace_mob.h"
}
