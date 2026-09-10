#include <mudlib.h>
#include <conditions.h>
#include "../wang.h"
inherit MONSTER;
inherit TEACHER;

void create()
{
	object ob1;
	::create();
	set_level(19);
	set_name( "Medic Wang", "王藥師" );
	add( "id", ({ "medic", "wang" }) );
	set_short("王藥師" );
	set_long(
@LONG
王藥師原本是行醫者公會的一員，他是行醫者公認的草藥權威，幾乎所有珍
貴藥草生長的地點都是他發現的。幾年前突然離開公會，來到這地方隱居。
此後每天不是出去採藥就是調製各種奇怪的藥，沒有人知道他想做什麼。
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 25 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "blunt", 100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set( "max_hp", 600 );
	set( "force_point", 100 );
	set( "hit_points", 600 );
	set_natural_armor( 100, 50 );
	set_natural_weapon( 30, 15, 25 );
	set( "special_defense", ([ "all": 50,"none":60]) );
	set( "aim_difficulty",([ "weakest":30,"vascular":20 ]) );
	set( "alignment", 500 );
        set( "inquiry", ([
		"poison" : "@@ask_poison",
		"herb" : "@@ask_poison",
		"train" : "@@ask_train",
		])
	);	
        set( "chat_chance", 2 );
        set( "chat_output", ({
                "王藥師喃喃地念著:「無根水三兩.. 付子五錢... 」\n",
                "王藥師站起來, 走出房間, 過一會兒拿了些藥草進來，開始調配。\n",
        }) );

	set_lessons( ([
		"venomlogy" : ({ 150,90 })
	]));

	set( "tactic_func", "my_tactic" );
	wield_weapon( MY_WEAPON );
	equip_armor( ITEM"deer_gloves.c" );
	ob1 = new(ITEM"box.c");
	ob1->move(this_object());

}

void init()
{
	teacher::init();
}

//
// msgs[random(sizeof(msgs))]
// but 這段常常被 call when fighting , 還是先算出來 size 多大比較好
//
int my_tactic()
{
	string *msgs = ({"\n王藥師從藥囊中抓出一把毒沙，往%s撒去!\n\n",
			 "\n王藥師袖中噴出一道黃色的水，噴的%s滿身都是!\n\n",
			 "\n王藥師的指甲中突然彈出一道青色的煙，直衝%s...\n\n",
			 ""});
	string msg1 = "王藥師哈哈大笑說道：「竟敢在用毒的祖宗前賣弄，你不知道這叫班門弄斧嗎?」\n 王藥師取出藥丸服下，竟自行解毒了。\n"; 
	object me,victim,env;
	int type;
	string msg;

	me = this_object();
	env = environment( me );
	if ( me->query("conditions/weak") ) {
		tell_room(env,msg1);
        	me->modify_stat("str",(int) me->query("weak"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}
	if ( me->query("conditions/slow") ) {
		tell_room(env,msg1);
        	me->modify_stat("dex",(int) me->query("slow"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}

	if ( ( me->query("conditions/simple_poison")) ) {
		tell_room(env,msg1);
		(CONDITION_PREFIX + "simple_poison")->remove_effect(me);
	}

//      機率

	victim = query_attacker();
	if ( random( 10 + victim->query_perm_stat("kar") ) > 14 )
		return 0;

	msg = sprintf( msgs[ (type = random(3)) ], victim->query("c_name") );
	tell_object(victim,
              "\n王藥師雙手一揮，大笑道 ： 「哈哈 !! 來得好 !! 正好來讓我試試藥 !!」 \n" );
	tell_room(env,msg,victim);
	switch(type) {
		case 0:
        		(CONDITION_PREFIX + "simple_poison") ->
                		apply_effect(victim,12,6);
			break;
		case 1:
        		(CONDITION_PREFIX + "weak") ->
                		apply_effect(victim,12,6);
			break;
		case 2:
        		(CONDITION_PREFIX + "slow") ->
                		apply_effect(victim,12,6);
			break;
		default:
			break;
	}
	return 0;	
}

void ask_poison(object visitor)
{

	if( (string) visitor->query("class") != "healer" ) {
	 	tell_object(visitor,"你不是醫生，我想你是不懂得藥性的人，還是算了吧\n") ;

	}  else {
		     tell_object(visitor,
"熟悉毒藥並不一定是壞事，如果用對地方..。我離開行醫者公會一段時間了,\n"
"這一段時間內，蒐集了一些配方，另外還有自己發現的。\n"
"如果你有興趣，我可以教你毒物學。如果下毒的技巧不夠好，你自己有可能中毒的。\n"
"藥方在後面房間，你去看看吧。\n"
			);
	}
}

void ask_train(object who)
{
	if ( (string) who->query("class") == "healer" ) {
		tell_object( who ,
"想跟我學毒物學(venomlogy)嗎? 你找對人了。我正好缺些解毒用的藥材，\n"
"如果你能帶一些給我,我很樂意教你的。\n");
	} else
		tell_object( who,
"很抱歉, 我只教行醫者, 你另請高明吧。\n");
		
}

// not finished ..
int check_trainee(object trainee)
{
	if ( (string) trainee->query("class") != "healer" ) {
		tell_object(trainee,"很抱歉, 這項技能我只傳授給行醫者。\n");
		return 0;
	}
	if (! (trainee->query_temp("give_herb/herb1")  && 
	     trainee->query_temp("give_herb/herb2")) ) {
		tell_object(trainee,"請你再拿些藥材給我吧。\n") ;
		return 0;
	}
	return 1;
}

int accept_item(object who, object item)
{
	if ( (string) item->query("ident") == "SWAMP_BERRY" ) {
		tell_object( who, "謝謝你，我正需要這味藥材。\n") ;
		who->set_temp("give_herb/herb1",1);
		item->remove();
	} else if ( (string) item->query("ident") == "SWAMP_MOSS") {
		tell_object( who, "謝謝你，我正需要這味藥材。\n") ;
		who->set_temp("give_herb/herb2",1);
		item->remove();
	} else if ( item->query("ident") ) {
		tell_object( who,"雖然我不需要這味藥, 還是謝謝你。\n");
		item->remove();
	}
	return 1;
}

void die()
{
	object killer,env,*inv;
	int i;
	env = environment( this_object() );
        inv = all_inventory( env );
	killer = query("last_attacker");
	if ( ! killer || ! env || !inv ) {
		::die();
		return;
	}

        i = sizeof(inv);
	tell_room(env,"王藥師說道:「你.. 你們會後悔的....」\n",this_object());
        while(i--) {
		if ( living(inv[i]) && ! inv[i]->query("npc") )
                	inv[i]->set_temp("kill_wang",1);
        }
     	::die();
}

