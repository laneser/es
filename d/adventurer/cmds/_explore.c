//#pragma save_binary

#include <mudlib.h>

#define MESSAGE ({"蹲下來開始檢查路邊的野花...\n","拿只放大鏡對地面猛瞧...\n","在地上挖了好大一個洞然後跳進去...\n","趴在地上東張西望...\n","伸手擦了擦額頭上的汗水...\n" })
inherit DAEMON;


int help();
int explore_work(object me,object env,int time);
int cmd_explore()
{
	int skill,tp_cost,sp_cost,hp_cost,time;
	object me, env;
	
	time = 5;
	me = this_player();
    if( me->query_attacker() )
        return notify_fail("你還在戰鬥喔，不要分心喔...\n");
    if( me->query_temp("explore_busy") )
    	return notify_fail("別鬧了，你不是正在作嗎。 \n");

	env = environment(me);
	
	if( !env ) return 0;
    if( !env->query("outside") )
        return notify_fail("這裡好像沒有什麼特別值得注意的自然物。 \n");	
	if( !skill = (int)me->query_skill("natural_history") )
		return notify_fail( "你沒有學過博物學，不用浪費時間啦 !!!\n");
	tp_cost = 60 - skill/5 ;
	sp_cost = 15 - skill/10 ;
	hp_cost = 20 - skill/10 ;
	
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("你太渴了，再不找點水來補充一下可不太好！\n");
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
	        return notify_fail("你精神力太差了，快點找地方休息吧！\n");
	if( !hp_cost || (int)me->query("hit_points") < (hp_cost + 1) )
	        return notify_fail("你就快駕鶴西歸了，還想要幹嘛啊！\n");
	                
	                
	else
		me->add("talk_points", -tp_cost );
		me->add("spell_points", -sp_cost );
		me->add("hit_points", -hp_cost );

	tell_object(me, set_color("你把袖子捲了起來，開始仔細的探索附近的一草一木 ! \n", "HIC",me) ); 
	
	me->set_temp("explore_busy",1);
	me->set_temp("block_command", 1 );
	me->set_temp("msg_stop_attack",
	         "( 你正於沉迷於探索大自然的樂趣之中！無法攻擊... )\n" );
	call_out("explore_work", 5, me, env, time);
	return 1;
}

int explore_work(object me,object env,int time)
{
	int skill,my_kar,my_pie,num,chance,n,i,delay;
	object thing;
	skill = me->query_skill("natural_history");
	delay = 40 - skill/10 - me->query_stat("pie")/2 ;
	if ( time < delay ) {
	time = time + 5 ;
	i = random(4);
	tell_object( me, set_color(
	 "你"+MESSAGE[i] , "HIY", me) );
	tell_room( env,
	                "你看到"+ me->query("c_name")+MESSAGE[i],me );
	
	call_out("explore_work", 5, me, env, time, delay);
	return 1;
	}
        num = env->query("explore_time");
	my_kar = me->query_stat("karma");
	my_pie = me->query_stat("piety");
	chance = 57 - my_pie/2 - skill/4 - my_kar/2 + num*10 ;
	me->delete_temp("msg_stop_attack");
	me->delete_temp("block_command");
	me->delete_temp("explore_busy");
	
	if ( random(chance) >3 ) {
	tell_object( me, set_color( 
		"你找了半天，什麼都沒有找到，你決定放棄搜索此處...\n", "HIY", me) );
	tell_room( env, 
		"你看到"+ me->query("c_name")+"從一堆草叢中鑽出來，臉上滿是失望的表情。\n\n" ,me );
                return 1;
                }
         switch( n= random(4) ) {
                    case 0: thing = new("/d/noden/monster/hornet");   break;
                    case 1: thing = new("/d/noden/monster/snake");   break;
                    case 2: thing = new("/d/adventurer/natural_history/unknow_tree");   break;
                    case 3: thing = new("/d/adventurer/natural_history/unknow_gem");   break;
                    default : break;
                    }
                  thing->move(environment(this_player()));
                  tell_object( me,
                      "皇天不負苦心人，你找到一"+thing->query("unit")+thing->query("c_name")+"...\n");
                  tell_room( env,
                      me->query("c_name")+"從草叢中找到了"+thing->query("unit")+thing->query("c_name")+"...\n",me);
                      
                  me->gain_experience(100);
                  if (n < 2) thing->kill_ob(this_player());
                  env->add("explore_time",1);
                  return 1;
}
int help()
{
write(
@C_LONG
指令格式: explore

這個指令能夠使你運用所學的博物學(natural_history) 知識，從大自然中
尋找有用的自然物，而發現與否的機率與你的博物學，運氣以及耐心都有關

C_LONG
);
    return 1;
}
