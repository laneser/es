// 少林寺七十二絕技「金剛杖法」
inherit "/d/martial/attack/modify";

void special_attack(object ob1, object victim)
{
  int damage;
  damage = ob1->query("monk_gonfu/king-kong") + (ob1->query("min_damage1")+ob1->query("max_damage1"))/2 ;

  if ( !ob1->query_attackers() || !victim )
       return ;
  tell_object( victim,
       sprintf("%s大喝一聲，露出金剛法像，對你重重一擊，令你疼痛難當\n\n",(string)ob1->query("c_name")) );
                           
  tell_room( environment(ob1),
       sprintf("\n\n%s大喝一聲，露出金剛法像，鎮攝當場，橫杖一揮將%s擊得搖搖晃晃，站不住腳。\n\n",(string)ob1->query("c_name"),(string)victim->query("c_name")),
       ({ victim, ob1 }) );
                            
  tell_object( ob1,
       sprintf("\n\n你運起金剛杖法的絕技，將%s一擊飛出。\n\n",(string)victim->query("c_name")) );

  victim->block_attack(2);                          
  victim->set_temp("msg_stop_attack",
          "( 你受到金剛杖法的震湯，一時無法動彈！ )\n)" );
  victim->receive_damage(damage);

  if (wizardp(ob1))
     printf("\n[ Receive_damage : %d ]\n\n",damage );
}

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
                    return 0;
           return 1;
}

string *attack_msg = ({
        "踏上一步，%s向%s擊去，勁勢十分強勁",
        "使出一招『掃蕩群魔』，%s掠地而出，直掃%s",
        "揮動%s，一時塵土飛揚，三道杖影透出，撲向%s",
        "大喝一聲，%s中宮直入，杖尖帶著一陣勁風，攻向%s",
        "雙手持%s使出最強一式『金剛伏魔』，內力如排山倒海般自杖頭湧向%s",
});

int *hits = ({ 30, 35, 30, 45, 50 });
int *pens = ({ 10, 22, 30, 40, 45 });
int *dams = ({ 7, 9, 12, 14, 17 });

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/king-kong");
	return ((hits[type-1] + random(lvl)/6)*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/king-kong");
	return  ((pens[type-1] + random(lvl)/6)*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;
        if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/king-kong");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/king-kong", 3*type+random(2*type));
	if (random(350)<lvl) special_attack(me,victim);
	return ((dams[type-1]+lvl/3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(5)]+"但是出手時顯得內力不足";
        return attack_msg[random(5)];
}
