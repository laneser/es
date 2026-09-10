
#include "../goomay.h"

inherit Mob_special;

void create()
{
	
	::create();
	set_level(4);
	set_name( "mama", "媽媽桑" );
	set_short( "媽媽桑" );
	set_long(
	"一個全身乾癟卻穿得很*暴露*的老婆婆，她正在照看著澡堂的生意。\n"
		 );
	set("alignment",100);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "unit", "個" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 50 ]) );
	set_natural_weapon(4,4,9);
	set_natural_armor(26,0);
        set("special_attack",(["damage_type" : "energy","main_damage" : 6,
                                "random_dam" : 3 , "hit_rate" : 15]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","媽媽桑舉起小板凳朝你頭上一陣亂砸 ....痛死了...\n\n");
set("c_room_msg","媽媽桑舉起她的小板凳朝");
set("c_room_msg2", "一陣亂打，把他打得暈頭轉向 ...\n");
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "媽媽桑大叫道：「臭小子 !! 連你祖媽我都要欺負 !! 」。\n",
	}) );
}
