//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// 這些參數是隨便定的，數目一樣就可以了
#define spirits ({ "fire","water","dark","moon","wood","solid","sword",\
				"grass","solid2",})
#define names ({ "火精靈","水精靈","黑暗精靈","月光精靈","木精靈","大地精靈",\
				"劍魂","草精靈","大地精靈2", })
#define files ({ "fire","water","dark","moon","wood","solid","sword","grass","solid2",})
#define levels ({ 13,10,17,15,8,19,16,4,19, })
#define combat ({ 1,0,1,0,1,1,1,0,1, })
#define cost_sp ({ 26,30,34,45,16,38,32,12,38, })

inherit DAEMON;

int help();
int can_summon(object me)
{
	mapping summon;
	string *type,str ;
	int i,j;

	if (!summon = me->query("demand")) {
		write("目前你無法召喚任何東東。\n");
		return 1;
	}
	str = "你目前能召喚的東東有 ： \n";
        type = keys(summon);
        for(i=0; i<sizeof(type); i++) {
        	j = member_array(type[i],spirits) ;
        	if ( j < 0 )
        		continue ;
         
          str += sprintf("  %-10s( %-10s)\t  %-10d\t  [%|6s] \n", names[j], 
          capitalize(type[i]),levels[j],
		( !combat[j]  ? "非戰時" : "戰時" ));
        }
        write(str);
        return 1;
}
	
int cmd_demand(string str)
{
	object me,victim;
	int i;

        if( !str ) return help();

        me = this_player();

	if ( str=="who" ) return can_summon(me);

	if (!me->query(SCHOLAR_SUMMON_SKILL+str)) 
             return notify_fail("呵 ! 別傻了 !! 你能召喚這種東東嗎？\n");
 
	i = member_array(str,spirits) ;
	if ( i < 0 )
                return notify_fail("呵 ! 別傻了 !! 你能召喚這種東東嗎？\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一個動作還沒有完成，無法動作。 )\n");

	if( me->query_temp("summon_busy") )
    	  return notify_fail("你目前正忙著跟剛剛召喚來的東東溝通，沒空想別的事情。\n"); 

        if (me->query_temp("summon_rest"))
          return notify_fail("你的精神力還不足以用來作下一次召喚，再休息一下吧。\n");

	if( environment(me)->query("no_summon"))
		return notify_fail( 
			"你怎樣也不能凝聚精神力，無法把你的需要傳達出去。\n");

	if ( !combat[i] && me->query_attacker())
		return notify_fail("你不能在戰鬥中召喚這個東東 ...\n");

        if ( combat[i] && !me->query_attacker())
                return notify_fail("你只能在戰鬥中召喚這個東東 ...\n");
//
	
        if ( (int)me->query_skill("polemic")< levels[i]*5 ) {
          write("你的辯術技能不夠驅使"+names[i]+"來幫助你。\n");
          return 1;
        }

        if ( (int)me->query_skill("yinyanglogy")< levels[i]*3 ) {
          write("你的陰陽學技能不夠驅使"+names[i]+"來幫助你。\n");
          return 1;
        }

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("你的精神不濟了，應該好好休息一下。\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("你集中精神開始利用心靈力量召喚"+names[i]+"來幫助你。\n","HIR"));
        me->set_temp("summon_busy",1);
        call_out("check_demand",1,me,i);
        return 1;
}
 
void check_demand(object me,int i)
{
  object mob;

  me->delete_temp("summon_busy");
  if (random(me->query_skill("polemic"))<=levels[i]) {
    write("你和"+names[i]+"之間的心靈傳遞沒有成功，召喚失敗。\n");
    return ;
  }
  else {
    seteuid(getuid());
    mob=new("/d/scholar/demand/spirit/"+files[i]);
// 去除與戰鬥無關的設定
    mob->set_perm_stat("str",random((int)me->query_perm_stat("str")*2/3)+levels[i]);
//    mob->set_perm_stat("int",random((int)me->query_perm_stat("int")*2/3)+levels[i]);
    mob->set_perm_stat("kar",random((int)me->query_perm_stat("kar")*2/3)+levels[i]);
//    mob->set_perm_stat("con",random((int)me->query_perm_stat("con")*2/3)+levels[i]);
    mob->set_perm_stat("dex",random((int)me->query_perm_stat("dex")*2/3)+levels[i]);
//    mob->set_perm_stat("pie",random((int)me->query_perm_stat("pie")*2/3)+levels[i]);
    mob->set_natural_weapon((int)me->query("weapon_class1")+levels[i],levels[i],(int)me->query("max_damage1")*3/5+levels[i]);
//    mob->set_temp("extra_ac",(int)me->query("armor_class")+levels[i]);
//    mob->set_temp("extra_db",(int)me->query("defense_bonus")+levels[i]);
    mob->set_skill("unarmed",100);
//    mob->set("max_hp","@@query_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",me);
    mob->my_action(me);
    return;
  }
}

int help()
{
		write( @C_HELP
指令格式: demand <對象名稱>

這個指令讓你用來召喚任何願意幫助你的精靈前來幫你。
要求他們來幫助你之前，你要想辦法和他們建立關係，有了良好的關係後
，他們都很樂意為你服務，不過偶而有些對象還是會跟你收取一些代價。

你可以用 demand who 指令來查詢你可以求助的對象。
C_HELP
		);
    return 1;
}
