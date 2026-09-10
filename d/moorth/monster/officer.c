#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(14);
	set_name( "Moorth Officer", "默爾斯軍官" );
	add( "id", ({ "officer" }) );
	set_short("默爾斯軍官" );
	set_long(
		"你看到一個默爾斯的軍官，他正在尋找敵人——並且企圖建立戰功\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set_natural_armor(30,25);
	set_natural_weapon(8,10,10);
    set( "special_defense", ([ "all":10 ]) );
    set( "aim_difficulty",
        ([ "critical":10, "vascular":10, "weakest":20 ]));
	
	set( "wealth/silver", 110 );
	set( "aggressive", 1 );
// set( "war_value", 20 );
   set( "war_value", 40 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set_skill( "block", 75 );
	set_skill( "defend", 80 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默爾斯軍官大叫: 天佑吾皇！榮耀歸我默爾斯、\n",
		"默爾斯軍官說道: 丟下武器，不要做無謂的抵抗！\n",
		"默爾斯軍官說道: 你們這些野蠻人，快向默爾斯帝國投降！\n"
	}) );

	ob1 = new( "/d/moorth/obj/longsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/shield" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("soldier") || who->id("officer") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默爾斯軍官挺身保護" + who->query("c_name") + "。\n",
		this_object() );
}
