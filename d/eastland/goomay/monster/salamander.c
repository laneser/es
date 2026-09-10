#include "../goomay.h"

inherit Mob_special;

void create()
{
	::create();
	set_level(10);
	set( "unit","只");
	set("killer",1);
	set_name("salamander", "火蜥蜴");
	add( "id", ({ "lizard" }) );
	set_short("火蜥蜴");
	set_long(
		"這是一種住在火旁以火為食的生物，生性殘暴的它什麼都吃。\n"
	);
	set_skill( "dodge", 50 );
	set_perm_stat("dex",15);
        set_perm_stat("str",15);
        set( "natural_armor_class", 50 );
        set( "natural_weapon_class1", 17 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
	set( "alignment", -450 );
	set( "wealth/copper", 400 );
        set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set("special_attack",(["damage_type" : "fire","main_damage" : 15,
                                "random_dam" : 10 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","\n火蜥蜴噴出一蓬炙熱的火花，「轟」的一聲炸在你身上..\n\n");
set("c_room_msg","火蜥蜴噴出一蓬火花，在");
set("c_room_msg2", "的身上猛烈燃燒 ...\n");
}
