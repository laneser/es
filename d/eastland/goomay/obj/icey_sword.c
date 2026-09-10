#include <../goomay.h>

inherit Weapon_special;

void create()
{
	set_name( "Sword of snow", "吹雪劍" );
	add( "id", ({ "sword" }) );
	set_short( "吹雪劍" );
	set_long(
		"這是一把奇特的短劍，劍刃上浮現出一片片六角形如雪花一般的\n"
		"印痕，雖然你只是看它一眼，但也似乎能感受到那股絲絲寒意。\n"
	);
	set( "unit", "把" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 37, 20, 32 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);

        set("special_attack",(["damage_type" : "cold","main_damage" : 10,
                                "random_damage" : 10 , "hit_rate" : 15]));
//        set("hit_func","special_attack");

set("c_msg","\n你的吹雪劍噴出一片奇冷的寒氣，冰凍敵人的身體。\n\n");
set("c_enemy_msg","的吹雪劍噴出一片奇冷的寒氣，冰凍你的身體。\n\n");
set("c_fail_msg","\n你的吹雪劍噴出一片奇冷的寒氣，卻冰到你自己 ! \n\n");
set("c_fail_room_msg","的吹雪劍噴出一片奇冷的寒氣，卻冰到他自己 ! \n\n");
}

int fail_to_use()
{
	object ob;
	if ( !(ob = present("flame shield", environment(this_object()) )) ||
			    !(ob->query("equipped")) )
	       return 1;
	else
	       return 0;
}
