#define LEVEL 19
#define NEED_SKILLS 95
#define COST_SP 38
#define SCHOLAR_SUMMON_SPIRIT "/d/scholar/demand/spirit/"

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辯術技能不夠驅使大地精靈來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的陰陽學技能不夠驅使大地精靈來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚大地精靈來幫助你。\n","HIM"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和大地精靈之間的心靈傳遞沒有成功，召喚失敗。\n");
  else {
    write("大地精靈對你說：沒問題...我馬上來幫你擊退敵人!\n");
    tell_object(me,set_color("你見到地面突然裂開，大地精靈從中衝了出來和你一起攻擊敵人。\n","HIM"));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，突然從地面裂開，出現一個大地精靈\n對"+me->query("c_name")+"的敵人發動攻擊。\n","HIM"),me);
    me->set_temp("summon_rest",1);
    seteuid(getuid());
    mob=new(SCHOLAR_SUMMON_SPIRIT"solid_spirit");
    mob->move(environment(me));    
    mob->set("master",me);
    mob->kill_ob(me->query_attacker());
    call_out("check_battle1",1,me,mob);
    call_out("check_battle2",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle1(object me,object mob)
{
  if (!mob)
    return;
  if (!me->query_attacker()) {
    tell_object(me,"大地精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n");
    tell_room(environment(mob),set_color("你見到地面裂了開來，大地精靈鑽了進去。\n","HIM"));
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else
    call_out("check_battle1",1,me,mob);
}

void check_battle2(object me,object mob)
{
  if (!mob)
    return;
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    tell_object(me,"大地精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n");
    tell_room(environment(mob),set_color("你見到地面裂了開來，大地精靈鑽了進去。\n","HIM"));
    mob->remove();
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else 
    call_out("check_battle2",4,me,mob);
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
