#include <mudlib.h>
#define BACKSTAB_ROOM1 "/d/thief/hall/backstab_room"
#define BACKSTAB_ROOM2 "/d/thief/hall/backstab_room2"
#define TIME_LIMIT 600
inherit ROOM;

void new_mob(object trainee);

void create()
{
	::create();
	set_short( "背刺測驗室");
	set_long(	@C_LONG_DESCRIPTION
這裡是小偷公會的秘密訓練室。專門給希望提升背刺能力的小偷們試身手
用的，這裡除了北方有一點光影跳動外，似乎沒有其他出口，不過東邊的牆上
好像掛著一塊告示(sign)，應該是一些說明吧 !! 你最好先看看。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set("c_item_desc",([
		"sign" : @SIGN
告示上寫著 :
    這裡是背刺測驗室，你將要接受測驗，在北方，有一個對手正等著你，
你可以用盡各種方法去取得他身上的鑰匙，然後才能打開最北邊的門回到公
會，這個過程有時間限制，小心應用你學到的各種技巧，也不要懷疑萬用小
刀的威力，希望你能順利過關 !!
 
    在你嘗試闖關的過程，失敗的狀況有三種 :
    
    1. 被對手重傷而死 	: 你的對手都是公會的前輩化裝的，出手自
			  有分寸，只會讓你"假死", 不過人難免會失手, 
			  請自己小心。
    2. 時間用盡		: 時間拖太長了，對手煩了，會把你趕出測驗室，那
			  你這次的測驗費就白交了。
    3. 你逃走了		: 斷線逾時或 quit 都視為闖關失敗。
	
    此外，闖關後不論成敗，請記得向泰勒斯要回你的裝備(equip)。

SIGN
	]) );
	set( "exits", ([ 
		"north" : BACKSTAB_ROOM2 ]) );
	set("pre_exit_func",([ "north" : "to_north" ]) );
	reset();
}

int to_north()
{
	object *invs;
	int i;
	if ( !query("begin_test") ) {
		invs = all_inventory(find_object_or_load(BACKSTAB_ROOM2));
		for ( i = sizeof(invs)-1 ; i >=0 ; i-- )
			if ( !userp(invs[i]) ) invs[i]->remove();

		new_mob(this_player());
		set("begin_test",time()+TIME_LIMIT );
		if ((object)query("tester") == this_player())
			this_player()->set_temp("skip_dead",1);
	}
	return 0;
}

void new_mob(object trainee)
{
	object mob;
	int lv,bs_lv;
	lv = (int)trainee->query_level();
	bs_lv = (int)trainee->query("thief_level/backstab");
	mob = new("/d/thief/hall/monsters/bs_mob");
	mob->set_level(lv);
	mob->set_natural_weapon(lv*3/2,lv,lv*12/10);
	mob->set_perm_stat("karma",lv/2);

	mob->set("hit_points",10+3*bs_lv);
	mob->set("max_hp",10+3*bs_lv);
	mob->move(BACKSTAB_ROOM2);
}

int fail_to_pass(object me)
{
	delete("begin_test");
	delete("tester");
	set("using",0);
	tell_object(me,"\n一個聲音說道 : 你花太多時間了 !! 下次再試吧 !!\n\n"); 
	me->delete_temp("skip_dead");
	me->move_player("/d/thief/hall/thief_guild","SNEAK");
	return 1;
}

int do_quit()
{
	tell_object(this_object(),
		"一個聲音說道 : 放棄啦? 好吧, 下次再試試看可能比較好。\n");
	delete("begin_test");
	delete("tester");
	set("using",0);
	return 0;
}

do_auc()
{
	tell_object(this_object(),"你不能在這裡進行交易 !!\n");
	return 1;
}

void init()
{
	int timer ;

	add_action("do_auc","auction");
	add_action("do_quit","quit");

	timer = query("begin_test") ;
	if ( ! timer ) {
		set("using",1);
		set("tester",this_player());
		return ;
	}
	if ( 
		(time() > timer) && 
		((object)this_object()->query("tester") == this_player())) {
		fail_to_pass(this_player());
	}
		return ;
}
