#define LEVEL 15
#define NEED_SKILLS 75
#define COST_SP 30

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辯術技能不夠驅使月光精靈來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的陰陽學技能不夠驅使月光精靈來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚月光精靈來幫助你。\n","HIY"));
        call_out("check_demand",2,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=LEVEL)
    write("你和月光精靈之間的心靈傳遞沒有成功，召喚失敗。\n");
  else {
    write("月光精靈對你說：沒問題...我馬上來幫你醫療!\n");
    tell_object(me,set_color("你見到一道黃光從天空直射而至，月光精靈從中走了出來，突然月光精靈全身放出一片\n金色光芒籠罩著你，你感覺一陣溫暖，月光精靈又消失在黃光之中。\n","HIY"));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，突然一道黃光從天空中直射而至，一隻\n月光精靈從中走了出來，你見到月光精靈突然全身放出一片金色光芒籠罩"+me->query("c_name")+"之後，\n又消失在黃光之中。\n","HIY"),me);
    me->set_temp("summon_rest",1);
    me->receive_healing(LEVEL+random(LEVEL));
    call_out("can_summon_again",5+random(LEVEL),me);    
  }
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
