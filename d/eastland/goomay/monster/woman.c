#include "../goomay.h"

inherit Mob_special;

void create()
{
	object ob;
	::create();
	set_level( 3 );
	set_name( "woman", "家庭主婦" );
	set_short( "家庭主婦" );
        set_long(
@C_LONG
她是一個典型的三姑六婆，買菜聊天是她最大的娛樂，現在她正
高興的一面挑東揀西一面到處噴口水，顯得很興奮。
C_LONG
);
	set( "gender", "female" );
	set( "race", "human" );

	set("hit_points", 100);
	set( "wealth/silver", 20 );
	set_natural_weapon( 4, 3, 7 );
	set_natural_armor( 16, 6 );
        set_c_verbs(({"%s用指甲抓向%s","%s用菜籃砸向%s","%s用腳踹向%s"}));
        ob = new( Obj"basket" );
        ob->move( this_object() );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
				"random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "那婦人用她的菜籃往你的頭上一陣亂砸..\n\n");
set("c_room_msg","那婦人像瘋了似的用菜籃亂砸");
set("c_room_msg2", "，把他打得哀哀叫 ...\n");
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "家庭主婦無奈地說：「獵人阿三病了，這幾天都沒有飛禽走獸可以進補 」。\n",
	})
	);

}

