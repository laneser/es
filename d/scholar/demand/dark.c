#define LEVEL 17
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define WEAPON_CLASS1 15
#define WEAPON_CLASS2 10
#define COST_SP 34

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")+WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")+WEAPON_CLASS2);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  me->set("weapon_class1",(int)me->query("weapon_class1")-WEAPON_CLASS1);
  me->set("weapon_class2",(int)me->query("weapon_class2")-WEAPON_CLASS2);
  return ;
}

int summon_me(object me)
{
        if ( (int)me->query_skill("polemic")< LEVEL*5 ) {
          write("你的辯術技能不夠驅使黑暗精靈來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< LEVEL*3 ) {
          write("你的陰陽學技能不夠驅使黑暗精靈來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < COST_SP ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-COST_SP);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚黑暗精靈來幫助你。\n","HIW"));
        call_out("check_demand",1,me);
        me->set_temp("summon_busy",1);
        return 1;
}
 
void check_demand(object me)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL)
    write("你和黑暗精靈之間的心靈傳遞沒有成功，召喚失敗。\n");
  else {
    write("黑暗精靈對你說：沒問題...我馬上來幫你增加戰鬥潛能!\n");
    tell_object(me,set_color("一團黑霧飄了過來，你耳邊聽到黑暗精靈對你說:讓我用暗黑鬥氣來提升你的戰鬥力吧 ! 不知它向你施了什麼法術，你突然覺的自己的精力大增。\n","HIW"));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，一團黑霧飄了過來，隱隱約約可以看到一隻黑暗精靈正對"+me->query("c_name")+"不知道施什麼法術。\n","HIW"),me);
    add_effect(me);
    me->set_temp("summon_rest",1);
    call_out("check_battle",LEVEL+random(LEVEL),me,mob);
  }
  return;
}

void check_battle(object me,object mob)
{
  if (!me->query_attacker()) {
    write("黑暗精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n"); 
    tell_room(environment(me),set_color("你見到黑暗精靈隨著黑霧消散掉了。\n","HIW"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  if (random(me->query_skill("polemic")+LEVEL)<=LEVEL) {
    write("黑暗精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n");
    tell_room(environment(me),set_color("你見到黑暗精靈隨著黑霧消散掉了。\n","HIW"));
    remove_effect(me);
    call_out("can_summon_again",random(LEVEL),me);
    return;
  }
  else 
    call_out("check_battle",4,me,mob);
  return;
}

void can_summon_again(object me)
{
  me->delete_temp("summon_rest");
  return;
}
