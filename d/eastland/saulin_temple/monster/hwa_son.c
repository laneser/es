#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level( 10);
	add("id",({"monk","son","hwa"}) );
        set_name( "Hwa son", "華尚" );
	set_short("華尚" );
	set_long(@C_LONG
眾生無我,一切隨緣... 少林也收了很多各類的非人生物,華尚是個蜥蜴人和尚
他在指力方面,有不錯的造詣,而且個性隨和 開朗...
C_LONG
	);
	set( "race","lizardman"); 
        set( "gender", "male" );
	set( "alignment",  300 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 50 );
	set_skill( "unarmed", 80 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon(19, 10, 20);
	set_natural_armor(50, 18);
        equip_armor(SAULIN_OBJ"silk_tail");

}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim,
		    "華尚尾巴一甩,雙手合十.... 使出『穿雲指』點了你的穴道！\n\n");
	tell_room( environment(), 
		  sprintf("華尚突然運氣一指，點住了%s的穴道！\n", victim->query("c_name")),
		({ victim, this_object() }) );
	victim->block_attack(6);
	victim->set_temp("msg_stop_attack", 
			 "( 你的穴道被點,一時之間無法動彈...... )\n" );
	return 1;
}
