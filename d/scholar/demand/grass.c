#define LEVEL 4
#define COST_SP 8

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辯術技能不夠驅使草精靈來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的陰陽學技能不夠驅使草精靈來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚草精靈來幫助你。\n","HIG"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和草精靈之間的心靈傳遞沒有成功\，召喚失敗。\n");
  else {
    write("草精靈對你說：沒問題...我馬上來幫你醫療!\n");
    tell_object(me,set_color("你見到遠處一個綠色的精靈站在一根草上飛了過來，草精靈將一片藥草敷在你的傷口上，\n你覺的一陣刺痛，草精靈又隨著風飛走了。\n","HIG"));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，你見到遠處一個綠色的精靈站在一根草\n上飛了過來，草精靈將一片藥草敷在"+me->query("c_name")+ "的傷口後，又隨著風飛走了。\n","HIG"),me);
    me->receive_healing(LEVEL+random(LEVEL));
    call_out("can_summon_again",random(LEVEL),me);
  }
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
