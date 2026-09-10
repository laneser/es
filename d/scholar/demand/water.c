#define LEVEL 10
#define COST_SP 20

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辯術技能不夠驅使水精靈來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的陰陽學技能不夠驅使水精靈來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚水精靈來幫助你。\n","HIB"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和水精靈之間的心靈傳遞沒有成功，召喚失敗。\n");
  else {
    write("水精靈對你說：沒問題...我馬上來幫你醫療!\n");
    tell_object(me,set_color("你見到天空一朵烏雲飄來，水精靈從中飄了出來，水精靈用手觸摸你的傷口，你覺的一陣\n冰涼，水精靈又隨著烏雲飄走了。\n","HIB"));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，突然天空中飄來一朵烏雲，一隻水精靈\n飄了出來，你見到水精靈伸出手去觸摸"+me->query("c_name")+ "的傷口之後，又隨著烏雲飄走了。\n","HIB"),me);
    me->set_temp("summon_rest",1);
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
