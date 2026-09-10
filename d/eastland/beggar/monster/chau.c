#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "chau", "趙無極" );
	add( "id", ({ "chau" }) );
	set_short( "趙無極" );
	set_long(@C_LONG
趙無極說是年紀很老,似乎倒也不老,說他年紀輕,卻又全然不輕, 總之是三十歲到
七十歲之間,相貌說醜不醜,說俊不俊。一副神經兮兮的樣子,整天口裡唸唸有詞誰
也不知道他到底在唸什麼? 
C_LONG	
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1200 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "kar", 20 );
        set_perm_stat( "dex", 30 );
	set_skill( "parry", 50 );
        set_skill( "block", 50 );
	set_skill( "dodge", 50 );
        set_skill( "unarmed", 50 );
        set("special_defense", ([ "all": 35,"none":40]) );
        set( "aim_difficulty",([ 
               "critical":60,"weakest":40,"ganglion":50,"vascular":80 ]) );
	set( "wealth/gold", 110 );
        set( "hit_points", 480);
        set( "max_hp", 480);
        set("max_fp", 400);
        set("force_points", 400);
        set("force_effect", 5);
        set_natural_armor(65,55);
        set_natural_weapon(55,23,33);
        equip_armor(DARMOR"chau_cloth");
        set("chat_chance",5);
        set("chat_output",({
          "趙無極喃喃自語說道:原來如此,原來如此。早知這般,悔不當初。受她打幾掌,又有何難?\n"
        }) );
        set_c_verbs( ({ "%s使了一招『偷龍轉鳳』向%s遞了過去",
                        "%s祭出一式 『大江東去』砍向%s",
                        "%s兩支手搖搖不定地向%s偷襲"
        }) );
}
int stop_attack()
{
	object slave, *tmp;

	slave = present( "donkey", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "大笨驢說道:竟敢攻擊我的主人，不要命了！\n" 
		"大笨驢向你撲了過來。\n"
	);
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( slave, tmp )==-1 ) {
		add_temp( "protectors", ({ slave }) );
		slave->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = slave->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		slave->kill_ob( this_player() );
}
void init()
{
    ::init();
    add_action("do_mount","mount");
}
int do_mount(string arg)
{
     object me;
     me=this_player();
     if (!(me->query("class")=="knight"))
        return 0;
     tell_object(me,"趙無極說道:ㄟ想偷我的驢子啊?\n");    
     return 1;
}