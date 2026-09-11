#include "../goomay.h"

inherit Mob_special;

void create()
{
	::create();
	set_level(5);
	set_name("woman", "洗衣婦");
	set_short("洗衣婦");
	set_long(
		"這個女人赤著雙腳、蓬頭垢面，她正坐在井邊洗衣服。\n"
	);
	set_skill( "dodge", 50 );
	set_perm_stat("dex",10);
        set_perm_stat("str",10);
        set( "natural_armor_class", 25 );
        set( "natural_weapon_class1", 6 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 14 );
	set( "alignment", 150 );
	set( "wealth/silver", 10 );
	set( "gender", "female" );
	set( "race", "halfling" );
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "那女人揮出□衣服，拍的一聲重重的打在你身上，你感到一陣劇痛..\n\n");
set("c_room_msg","那女人揮出□衣服，把");
set("c_room_msg2", "打得暈頭轉向 ...\n");

}
