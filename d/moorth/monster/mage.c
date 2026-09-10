#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "Moorth Magician", "默爾斯魔法師" );
	add( "id", ({ "magician" }) );
	set_short( "默爾斯魔法師" );
	set_long(
		"你看到一個默爾斯的魔法師，他的口中正喃喃地念著....攻擊法術的咒文！\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -800 );
	set( "hit_points", 350 );
	set( "max_hp", 350 );
	set( "special_defense", ([ "all": 40,"none":20 ]) );
    set("aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":15, "ganglion":30 ]));
	
	set_natural_armor(30,30);
	set_natural_weapon(10,10,10);
	set( "wealth/silver", 600 );
	set( "wimpy", 15 );
	set( "killer", 1 );
	set( "tactic_func", "my_tactic" );
// set( "war_value", 80 );
   set( "war_value", 160 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_skill( "wand", 100 );
	set_skill( "dodge", 90 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默爾斯魔法師大叫: 你們這些愚蠢無知的諾頓人，通通給我下地獄去吧！\n",
		"默爾斯魔法師說道: 殺死你們這些垃圾簡直就是浪費我的時間！\n",
		"默爾斯魔法師說道: 諾頓王在哪裡？叫他滾出來！\n"
	}) );

	ob1 = new( "/d/moorth/obj/wand" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/robe" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

int my_tactic()
{
	object *victim;

	if( !(victim= query_attackers()) ) return 0;
	if( random(20)<4 ) {
		tell_room( environment(this_object()), 
			"默爾斯魔法師口中念道: Kha-ta-mig'sen-gyr-da .....\n"
			"突然，一團燃著熊熊烈火的光球在你眼前「轟」的一聲炸開，你感到一陣灼熱的劇痛！\n",
			this_object() );
		victim->receive_special_damage("fire", 50);
		return 1;
	} else return 0;
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("magician") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默爾斯魔法師挺身保護" + who->query("c_name") + "。\n",
		this_object() );
}
