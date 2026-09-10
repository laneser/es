#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
        set_name( "fire monster", "火焰獸" );
        add( "id", ({ "monster" }) );
        set_short( "火焰獸" );
        set_long( @C_LONG
你看到一隻渾身發出紅色火焰的妖怪，它的雙眼散發出一種妖異的光芒
，即使是身經百戰的你，面對著這樣一隻根本不可能存在於世上的妖物
，也忍不住心中直冒寒意。
C_LONG
);
	set("killer",1);
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set("defense_type","dodge");
	set( "alignment", -1500 );
	set( "natural_armor_class", 70 );
	set( "natural_defense_bonus", 30 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n火焰獸噴出一蓬火焰，燒灼你的身體 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
		"\n火焰獸散發出強烈的光芒，你的眼睛一陣刺痛 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
			tell_object( victim[i], "你的墨鏡擋住了刺眼的強光。\n\n");
		else
		{
	        if( victim[i]->query("stop_attack") ) continue;
	        victim[i]->block_attack(8);
	        victim[i]->set_temp("msg_stop_attack", 
	          "( 你現在什麼也看不到 ! )\n" );
		}
	}
	return 1;
	}
	return 0;
}

void die()
{
		tell_room( environment(this_object()), 
			"火焰獸大叫：「黑暗之母 !! 救我 !!」 ....\n\n"
			"一道黑色的煙霧突然籠罩住火焰獸，然後消失的無影無蹤\n"
			"你聽到一個聲音從你的背後中發出: 「你以為打敗了無能的火焰獸，事情就會這樣就結束嗎？哈哈哈 !!」\n\n"
			"你回頭一看，一個女人正站在你的背後。她手上捧著一尊女神像\n"
			"「受死吧 !!」她大叫一聲，變身成為一隻人頭蛇身的妖怪\n\n" ,
			this_object() );
		set( "alt_corpse", Mob"snake" );
		::die(1);
}
