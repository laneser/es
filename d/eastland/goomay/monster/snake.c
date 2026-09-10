#include <../goomay.h>
#include <stats.h>
#include <conditions.h>
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
        set_name( "daemonic snake", "蛇魔女" );
        add( "id", ({ "snake" }) );
        set_short( "蛇魔女" );
        set_long( @C_LONG
你看到一隻人頭蛇身的妖怪，它的雙眼散發出一種妖異的光芒，即使
是身經百戰的你，面對著這樣一隻根本不可能存在於世上的妖物，也
忍不住心中直冒寒意。
C_LONG
);
	set("killer",1);
	set("gender","female");
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 26 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "parry", 100 );
	set( "alignment", -1500 );
	set( "natural_armor_class", 85 );
	set( "natural_defense_bonus", 35 );
	set( "natural_weapon_class1", 50 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
    sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	if ( !victim = query_attackers() ) return 0 ;
        spec=random(100);
        if ( spec>50 ) return 0;

	if (spec <20)
	{
	tell_room( environment(this_object()), 
		"\n蛇魔女噴出一灘酸液，腐蝕你的身體 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "acid", 30+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}

	if ( spec<30 ) 
	{
        tell_room( environment(this_object()), 
		"\n蛇魔女噴出一團毒霧，你感到一陣暈眩 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim[i], 10, 7 );
		return 1;
	}

	if ( spec<50)
	{
	tell_room( environment(this_object()), 
		"\n蛇魔女用她那對妖異的眼睛盯著你看，你的腦中突然一片空白 !!\n\n" ,
		 this_object() );
	for( i=0; i<sizeof(victim); i++ )
		(CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5 );
	return 1;
	}

	return 0;
}

void die()
{
	object ob1;
	ob1 = new( Obj"statue" );
	ob1->set("who_get_me",query("last_attacker")->query("name"));
        ob1->move(this_object());
                ::die(1);
	tell_room( environment(this_object()), @FLEE
一道黑色的煙霧突然籠罩住蛇魔女，你衝進黑霧中，卻見女神像發出一片聖潔的
銀光逐漸向黑霧中隱去，你趕緊用手抓住它，只覺得一股極強的力道從彼端傳來
，然後消失的無影無蹤，你不禁跌了開去，等你站起身來，黑霧已經散去了。

一陣刺耳的笑聲回湯在你的耳際: 嘻嘻嘻嘻 ... 愚蠢的人啊 ...這次小讓你了，
別以為黑暗的力量會就此放手 ... 我會回來的 ...

FLEE
		,this_object() );
}
