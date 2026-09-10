#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "drunk", "醉漢" );
	set_short( "醉漢" );
	set_long(
		"一個渾身酒臭的醉漢，看他失意潦倒的樣子，不知道是遭到什麼不幸\n"
		"還是自甘墮落。他正追著過路的人亂打，好像全世界的人都對不起他似的。\n"
	);
		set("aggressive",1);
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
		set_skill( "parry", 60 );
		set_skill("blunt",60);
		set( "gender", "male" );
		set( "race", "orc" );
		set( "alignment", -400 );
        set_natural_armor( 46, 18 );
        set_natural_weapon( -7,1,4);
                        	
		equip_armor( Obj"coat" );
		wield_weapon(Obj"club");
}
