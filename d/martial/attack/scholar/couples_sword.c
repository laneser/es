
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last, spouse_name, name2;
        object spouse, env;
        

	lvl = (int)me->query("scholar_gonfu/couples_sword");
	if( undefinedp(lvl) ) return 0;
        spouse_name = me->query("spouse");
        
        if (!spouse_name) {
          tell_object(me,"光棍是無法瞭解這套劍法的精髓的。\n");
          return 0;
        }
        
        env = environment(me);
        spouse_name = lower_case(spouse_name);
        spouse = find_living(spouse_name);
        if ( !spouse || !present(spouse,env) ) {
          tell_object(me,"因為缺少你另一半的輔助而無法施展這套劍法。\n");
          return 0;
	}
	/* 給怪物使用時預防錯誤 */
        name2=lower_case(spouse->query("spouse")); 
        if (name2!=me->query("name")){
          tell_object(me,"雖然名字相同, 可是對方卻不是你的配偶。\n");
          return 0;         
        }
	if (spouse->query("attack_skill")!="scholar/couples_sword"){
          tell_object(me,"因為缺少協助而使你無法施展這套劍法。\n");
 	  return 0;
	}
        if (!spouse->query_attackers())
          spouse->kill_ob(victim);   

	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "couples_sword1"  : type = 1;  break;
			case "couples_sword2"  : type = 2;  break;
			case "couples_sword3"  : type = 3;  break;
			case "couples_sword4"  : type = 4;  break;
			case "couples_sword5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	
        /* for some special case only */
        if (!me->query_temp("c_spouse"))
          me->set_temp("c_spouse",spouse->query("c_name"));  
	me->set_temp("extra_db/couples_sword", 3 + lvl/5);
	me->set_temp("last_attack_skill", ("couples_sword"+(string)type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *msg_one = ({
"手中%s打橫和",
"的長劍一挫，並肩殺向%s",
"倒翻%s，劃劍成弧，封住敵人的攻勢，",
"趁機攻向%s",
"一振%s，以輕盈身法配合著",
"，翻出朵朵劍花刺向%s",
"一式『情投意合』，運劍如飛，配合著",
"，一左一右攻向%s",
"劍式稍歇，與",
"兩人真力灌入%s，『與子成曰』一出，嗤嗤輕響，無數劍氣已罩住%s",
"身形微動，緊握%s，『與子偕老』一出，人已搶至敵人身後，與",
"一前一後夾攻%s"
});

string *msg_two = ({
"身形一變，一挽%s，攻勢綿綿不絕，就如同無盡地濃情蜜意一般攻向%s",
"與%s人劍合一，挾著漫天劍氣卷向%s"
});

string *msg_three = ({
"劍劃如虹，接連三式『比翼雙飛』，劍式遊走不定，%s劍光點點刺向%s",
"一聲清吟，長劍伴脫手疾射而出，一招『蕭史乘龍』，%s在空中幻出一道金光直射%s",
"手執%s，腳踩七星，倒轉五行，使出一招『小喬初嫁』，躲閃過敵人的攻擊並趁隙遞出一劍攻向%s",
"手持%s緩緩斜挑，一式『弄玉吹簫』，只見鳳蕭聲動，五色劍光流轉不息朝向%s射去"
});

int *hits = ({ 35, 40, 45, 50, 55 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 10, 14, 18, 22, 25 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
  if( type < 1 || type > 5 ) return 0;
  if( (int)me->query("force_points") < query_need_fp() ) return -20;
  return ((hits[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
    if( type < 1 || type > 5 ) return 0;
    if( (int)me->query("force_points") < query_need_fp() ) return -20;
    return ((pens[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
	if (!environment(me)->query("PK_ZONE"))
	  me->add("gonfus_exp/couples_sword", 5*type+random(10));
        lvl = (int)me->query("scholar_gonfu/couples_sword");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string c_spouse;
        int type_ext;
        
	if( type < 1 || type > 5 ) return 0;
        type_ext = type*2 - (int)random(2);
        c_spouse = me->query_temp("c_spouse");
        switch (type) {
          case 1 : 
          case 2 :
          case 3 :
            return sprintf("%s%s%s",msg_one[(type_ext-1)*2],
                           c_spouse,msg_one[(type_ext-1)*2+1]);            
            break; 
          case 4 :
            return msg_two[(type_ext-7)];        
            break;
          case 5 :
            if (me->query_temp("enhant_seq")==1)
              return msg_three[(type_ext-9)];
            else
              return msg_three[(type_ext-9)];  
          default :
            return 0;
        }
}
