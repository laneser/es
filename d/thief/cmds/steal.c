//#pragma save_binary
#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })

#include <mudlib.h>

inherit DAEMON;
/*
void announce( string msg )
{
    object *usr;
    int i;
    usr = users();
    i = sizeof(usr);
    for( --i ; i >= 0; i-- ) {
    	if( !environment(usr[i]) ) continue;
        tell_object( usr[i], set_color(msg, "HIR", usr[i]) );
	}
}
*/
void remove_block(object me)
{
	me->delete_temp("block_command");
	return;
}

int steal_idle(object me,int succeed,object target,object item)
{
	mapping wealth;
	string type,*coins;
	int coin,i;
	me->set_temp("stealed",0);
	if ( !target || nullp(target) || (int)target->query("hit_points") < 1 ) {
		write("真不幸，那傢伙已經死了 ...\n");
		return 1;
	}
	if ( !present(target,environment(me)) ) {
		write("你要偷的對象已經不在這裡了 !!\n");
		return 1;
	}
	tell_object(me,set_color(
		sprintf("趁著%s不留意的時候，你小心的把第三隻手伸向%s ...\n",
			target->query("c_name"),
			( !item ? target->query("c_name") : item->query("c_name")) )
			,"HIY") );
	
	if ( ! succeed ) {
	tell_object(me,set_color(
		sprintf("%s突然轉過頭狠狠地瞪了你一眼，忿忿的向你衝過來 ...\n",
			target->query("c_name")),"HIM") );
	tell_object(target,set_color(
		sprintf("你突然感到怪怪的，原來是%s的手正在你的揹包中摸啊摸的 ..\n"
			,me->query("c_name")),"HIY") );
// announce 太吵了，不爽的人自己喊吧 :P)
/*
	if ( target->query("user") )
		announce(sprintf("%s(%s)大喊 : 小偷 !! 小偷 !! %s(%s)是小偷 !!!\n",
					target->query("c_name"),capitalize(target->query("name")),
					me->query("c_name"),capitalize(me->query("name"))) );
*/
	if ((int)target->query_level() > 5 ) {
		target->kill_ob(me);
		me->kill_ob(target);
        me->block_attack(4);
        me->set_temp("block_command",1);
        me->set_temp("msg_stop_attack",
       		"( 哎呀 ! 偷東西被發現了，你一陣手忙腳亂！ )\n" );
       	call_out("remove_block",3,me);
		}
	} else {
		if ( item ) {
			if ( !item->move(me))
				tell_object(me,set_color("呵呵呵 ... 得手了 ...\n","HIY"));
			else
				tell_object(me,set_color("呃 .. 太重了，拿不動 ...\n","HIC"));
		} else {
		if ( !wealth = target->query("wealth") ) {
			tell_object(me,"你努力的在他的錢包摸啊摸 ... 可是連一毛錢都找不到 ...\n");
			return 1;
		}
		coins = keys(wealth);
		type = coins[random(sizeof(coins))];
		coin = ( wealth[type] > 100 ? 100 - random(10) : random(wealth[type]+1) );
		if ( coin ) {
			tell_object(me,set_color("咦 ! 撈到了 ... 嘻嘻嘻 ... 你狠狠地撈了一大把錢幣 ...\n","HIY"));
			me->add("wealth/"+type,coin);
			target->add("wealth/"+type,-coin);
		} else
			tell_object(me,"喔 ~~ 他好像發現了，你趕快把手縮回來，沒偷到半毛錢 ...\n");
		}
	}
	return 1;
}
int check_steal(object me,object target)
{
	int level,iq,dex,kar,rate1,rate2;

	if ( target->query("no_steal") ) return 0;
//	level = (int)this_player()->query_level()*2-(int)target->query_level();
	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
/*
	rate1 = level*level/8+kar+kar+dex+dex+iq;
   	rate1 = rate1*(int)me->query_skill("steal")/100;
   	rate1 = ( rate1 > 93 ? 93 : rate1 ) ;
	rate2 = level*level/6+kar+dex+iq;
   	rate2 = (rate2 + (int)me->query_skill("peep"))/2;
   	rate2 = ( rate2 > 93 ? 93 : rate2 ) ;
*/
	level = (int)me->query_skill("peep")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + iq + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	level = (int)me->query_skill("steal")/5 - (int)target->query_level() +5;
	level = ( level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
	rate1 = RATE[level] + iq + dex + dex + kar ;
	if ( random(120) > rate1 ) return 0;
	return 1;
/*
   	if ( (random(100) < rate1) && (random(100) < rate2 ))
   		return 1;
   	else
   		return 0;
*/
}
int help();
int cmd_steal(string arg)
{
	string tmp1,tmp2;
	object target,item;

	if ( this_player()->query_temp("stealed") )
		return notify_fail("你只有三隻手，而且第三隻已經伸出去了 ...\n");
	if ( ! arg )
		return notify_fail("你要偷誰的東西？\n");

	if ( sscanf( arg,"%s from %s",tmp1,tmp2) != 2 ) return help();
		if ( ! target = present(tmp2,environment(this_player()) ) )
			return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
		if ( ! living(target) )
			return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
		if ( tmp1 != "money" && ! item = present(tmp1,target ) )
			return notify_fail(target->query("c_name")+"沒有帶著叫"+tmp1+"的東東。\n");

	if ( target == this_player() )
		return notify_fail("偷自己的東西做什麼啊?\n");
// 預防利用偷東西失敗攻擊 no_attack mob
	if ( target->query("no_attack") )
		return notify_fail("你不能偷他的東西。\n");
// 不能偷 invisible 的 player
	if ( !visible(target,this_player()) || target->query("invisible_player") ) 
		return notify_fail("你想背刺誰？\n");

	if ( wizardp(target) ) {
		write("你怎麼能偷勞苦功高的巫師呢？..*puke*\n");
		return 1;
	}

	if ( item && (item->query("prevent_drop") || item->query("wielded") ||
			item->query("equipped")) ) 
	return notify_fail("別傻了 !! 這件東西你偷不走的 ...\n");
	write(set_color(sprintf("你開始用眼角的餘光偷偷留意%s的一舉一動 ...\n",
			target->query("c_name") ),"HIY"));
	this_player()->set_temp("stealed",1);
	call_out("steal_idle",5+random(4),this_player(),
			check_steal(this_player(),target),target,item );
	return 1;
}

int help()
{
	write (@HELP
Usage: steal <object> from <target>
	   steal money from <target>

這個指令能使你在別人毫不知覺的情況下偷走他沒有裝備的物品、金錢甚至
他揹包裡的袋子。在下手"借"別人的東西之前，最好養成先觀察觀察的好習
慣，隨手亂摸是很容易被發現的。

HELP
);
	return 1;
}
