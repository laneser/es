#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1;

	::create();
	set_level(8);
	set_name( "Moorth Soldier", "默爾斯士兵" );
	add( "id", ({ "soldier" }) );
	set_short( "默爾斯士兵" );
	set_long(
		"你看到一個默爾斯的士兵，他正在尋找敵人——並且企圖建立戰功。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set( "wealth/silver", 50 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 30 );
// set( "war_value", 5 );
   set( "war_value", 10 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 30 );
	set_skill( "defend", 40 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默爾斯士兵大叫: 拉娜西斯女皇陛下萬歲！\n",
		"默爾斯士兵說道: 丟下你的武器乖乖受死吧！\n",
		"默爾斯士兵說道: 你們不可能贏的，勝利是屬於默爾斯帝國的！\n"
	}) );

	ob1 = new( "/d/moorth/obj/shortsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("soldier") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默爾斯士兵挺身保護" +who->query("c_name") +"。\n",
		this_object() );
}
