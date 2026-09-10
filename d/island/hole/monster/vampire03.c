#include <../hole.h>

inherit REPORT;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Vampire","小吸血蝙蝠" );
	add("id",({ "kill_vampire2","bat","vampire" }) );
	set_short( "小吸血蝙蝠" );
	set_long(@LONG
    一隻吸血蝙蝠正倒掛在巖壁上，一雙泛紅的眼睛緊盯著你不放
，似乎正盤算著要將你當作晚餐。你最好在它攻擊你之前趕快離開這裡。
LONG
		);
	set( "alignment",-500 );
	set_perm_stat( "dex",15 );
	set_perm_stat( "kar",25 );
	set_skill( "dodge",45 );
	set_natural_armor( 60,10 );
 	set_natural_weapon( 30,5,20 );
 	set( "killer",1 );
	set_c_limbs( ({ "頭部","身體","翅膀","爪子" }) );
	set_c_verbs( ({ "%s用它長滿利牙的嘴咬向%s","%s用它的利爪抓向%s","%s用它的翅膀拍向%s" }) );
	set( "tactic_func","my_tactic" );
}

int my_tactic()
{
	object victim;
	string him;

	if( random(20)>3 || !(victim=query_attacker()) ) return 0;
	else
	{
	him = victim->query( "c_name" );
	tell_object(victim,"\n吸血蝙蝠飛到你的脖子上狠狠的吸了一大口鮮血\n\n");
	tell_room(environment(this_object()),
	"吸血蝙蝠突然飛到"+him+"的脖子上狠狠地吸了一大口鮮血\n\n",victim);
	victim->receive_damage( 10 + random(15) );
	report( victim );
	return 1;
	}
}
