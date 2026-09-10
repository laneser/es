#include <mudlib.h>
#define BACKSTAB_ROOM1 "/d/thief/hall/backstab_room"
#define TRAIN_ROOM "/d/thief/hall/thief_trainroom"

inherit MONSTER;
void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("maskman", "蒙面人");
	set_short( "蒙面人");
	set_long( @LONG
他就是你這次測試的主考官，也許他是你的前輩，平時也曾在一起哈拉打屁，
但是現在他戴著一個沒有表情的小丑面具，精光四射的眼睛冷冷地盯著你，好
像正在尋找你的弱點。

	"用任何方法擊敗我吧 !! " 他的聲音彷佛從地底傳來 ...

LONG
	);
	set_skill( "dodge", 80 );
	set("gender","male");
	set( "race", "human" );
	set("exp_reward",1);
	set("unbleeding",1);
	set("aim_difficulty",
		([ "vascular":35, "ganglion":50 ]) );
	set("tactic_func","my_tactic");
	set("alt_corpse","NONE");
}

int my_tactic()
{
	object killer;
	killer=this_object()->query_attacker();
	if ( ! killer ) 
		return 0;
	if ( ((int) killer->query("hit_points") * 100 / (int) killer->query("max_hp")) < 25 ) {
	this_object()->cease_all_attacks();
	killer->cease_all_atackers();
	tell_object(killer,
		"蒙面人賊賊的笑道 : 哈哈 !!你不行了, 放棄吧 !!\n"
		"蒙面人啟動機關後突然消失的無影無蹤。\n");
	    killer->move(TRAIN_ROOM);	
	    BACKSTAB_ROOM1->set("using",0);
	    BACKSTAB_ROOM1->delete("begin_test");
	    BACKSTAB_ROOM1->delete("tester");
	    this_object()->remove();
	}
	return 0;	
}

void die()
{
	object killer ,ob;
	if ( killer = (object)query("last_attacker")) {
	
	killer->set_temp("pass_test",1);
	tell_object(killer,
		"蒙面人賊賊的笑道 : 哈哈 !!你已經證明你的能力了，\n"
		"過關去吧 !! 打得我這麼痛，下次見面 ... 嘿嘿 ...\n\n"
		"蒙面人突然消失的無影無蹤。\n");
	}
	::die(1);
}
