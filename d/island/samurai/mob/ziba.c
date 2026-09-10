#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Teacher ziba", "劍術老師 甘錫巴" );
	add( "id", ({ "teacher","ziba" }) );
	set_short( "Teacher ziba", "劍術老師 甘錫巴" );
	set_long(@QQQ
你眼前是一個體型肥胖頭大大的男子,看起來像一隻河馬一樣,讓你懷疑像這樣的
人如何能當劍術老師
QQQ
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 15 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 55,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 24 );
	set( "natural_weapon_class2", 20 );
	set( "natural_min_damage2", 10 );
	set( "natural_max_damage2", 18 ); 
        set( "special_defense",([ "all":10,"none":25 ])); 
        set( "aim_difficulty",([ "critical":85,"weakest":30,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty",5);  
	set( "alignment", 2000 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉", "肚子"  }) );
        set_skill( "parry",80 );
        set_skill( "longblade",100 );
        set_skill( "two-weapon",100 );
        set_skill( "tactic",100 );
        set( "tactic","berserk" );
        set( "wealth" , ([ "gold": 110 ]) );
        set( "chat_chance",15);
        set( "att_chat_output", ({@AAA
甘錫巴大喝道：哪裡來的笨蛋，居然會向劍術老師挑戰！！！
AAA
,@BBB
甘錫巴說：小子你再不走我可就不客氣了！！！！
BBB
             }) );
        wield_weapon2(MOBJ"fish_sword.c");    
        wield_weapon(MOBJ"bird_sword.c");
        equip_armor(MOBJ"fencing_cloth.c");
        equip_armor(MOBJ"white_headband.c"); 
}
