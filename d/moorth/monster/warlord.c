#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2, ob3, ob4, ob5, ob6;

	::create();
	set_level(19);
	set_name( "Moorth Warlord", "默爾斯指揮官" );
	add( "id", ({ "warlord" }) );
	set_short( "默爾斯指揮官" );
	set_long(
		"你看到默爾斯軍隊的指揮官，他正在設法佔領諾頓王國的任一個城鎮，以便\n"
		"建立軍事據點。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set_natural_armor(50,30);
	set_natural_weapon(15,12,15);
	set( "wealth/silver", 400 );
	set( "hit_points", 650 );
	set( "max_hp", 650 );
	set( "special_defense", ([ "all": 40,"none":20 ]) );
	set( "aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":30, "ganglion":15 ]));
        	     
	set( "pursuing", 1 );
	set( "killer", 1 );
// set( "war_value", 100 );
   set( "war_value", 200 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "defend", 100 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默爾斯指揮官冷笑道: 凡是敢阻擋我默爾斯軍團者，格殺勿論！\n",
		"默爾斯指揮官說道: 就憑你這點能耐，也敢在我面前撒野？\n",
		"默爾斯指揮官說道: 默爾斯的大軍馬上就會突破結界，你們的軍隊是絕對擋不住的！\n"
	}) );

	wield_weapon("/d/moorth/obj/moraz_blade");
	equip_armor("/d/moorth/obj/cape");
	equip_armor("/d/moorth/obj/shield");
	equip_armor("/d/moorth/obj/platemail");
	equip_armor("/d/moorth/obj/helmet");
	ob6 = new( "/d/moorth/obj/gauntlets" );
	equip_armor("/d/moorth/obj/gauntlets");
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("warlord") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({ this_object() }) );
		add_temp( "protectees", ({ who }) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默爾斯指揮官挺身保護" + who->query("c_name") + "。\n",
		this_object() );
}
