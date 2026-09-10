#include <mudlib.h>
#include <daemons.h>
#define AC_EFFECT 15
#define DB_EFFECT 8
#define WC_EFFECT 8
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;

string str1="木精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n";
string str2="你見到木精靈跳回樹洞，樹又縮了回去。\n";
string str3="HIG";

void create()
{
	::create();
	set_level(8);
	set_name( "wood spirit", "木精靈" );
	add( "id", ({ "spirit" }) );
	set_short( "木精靈" );
	set_long(
		"一個看似槁木的精靈。\n"
	);
	set( "unit", "個" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
        set( "invisible",1);
	set_skill( "dodge", 50 );
}

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  return ;
}

void check_battle1(object me)
{
  if (!this_object())
    return;
  if (!me->query_attacker()) {
    remove_effect(me);
    END->bye_bye(me,this_object(),8,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle1",1,me);
  return;
}

void check_battle2(object me)
{
  if (!this_object())
    return;
  if (random(me->query_skill("polemic"))<=8) {
    remove_effect(me);
    END->bye_bye(me,this_object(),8,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle2",4,me);
  return;
}

int my_action(object me)
{
 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"木精靈對你說：沒問題...我馬上來幫你增加戰鬥潛能!\n");
   tell_object(me,set_color("平地中長出一棵樹來，一隻木精靈從樹洞中跳了出來，木精靈說：讓我用大自然的力量來提升你的戰鬥力吧 ! 不知它向你施了什麼法術，你突然覺的自己的精力大增。\n","HIG",me));
    tell_room(environment(me),set_color("你見到"+me->query("c_name")+"神情專注的念著一些咒語，平地中長出一棵樹來，一隻木精靈從樹洞中跳了出來，對著"+me->query("c_name")+"不知道施什麼法術。\n","HIG",me),me);
        add_effect(me);
        call_out("check_battle1",1,me);
        call_out("check_battle2",8+random(8),me);
	return 1;
}
