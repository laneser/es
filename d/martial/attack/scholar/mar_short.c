inherit "/d/martial/attack/modify";

void special_attack(object ob1,object victim)
{
  string t_type, t_color, ob1_name, vic_name;
  int t_ap; 
  if ( !ob1->query_attackers() || !victim  ) {
    return ;
  }
      t_type = (string)ob1->query("tactic"); 
      ob1_name = (string)ob1->query("c_name");
      vic_name = (string)victim->query("c_name");
  
      switch (t_type) {
      case "berserk" :
        t_ap = 5;
        t_color = "HIY";
        break;
      case "melee" :
        t_ap = 6;
        t_color = "HIG";
        break;
      case "assault" :
        t_ap = 4;
        t_color = "HIR";
        break;
      default :
        t_ap = 6;
        t_color = "HIG";      
      }
      tell_object( victim, sprintf("%s的劍招使你受到了%s的傷害\n\n",
              ob1_name,set_color("嚴重",t_color)));        
      tell_room( environment(ob1), sprintf("\n\n%s的劍招使%s受到%s的傷害\n",
              ob1_name, vic_name, set_color("嚴重",t_color)), 
              ({ victim,ob1}) );                   
      write(sprintf("\n\n你的劍招使得%s受到了%s的傷害\n\n",
             vic_name, set_color("嚴重",t_color)));
      victim->receive_damage((int)ob1->query("scholar_gonfu/mar_short")/t_ap);
      return;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/mar_short");
	if( undefinedp(lvl) ) return 0;
        if ( me->query("tactic")=="flank") {
          tell_object(me,"因為錯誤的戰術而使你無法使用這種劍法。\n");        
          return 0;
        }
        if ( !me->query("tactic") ) {
          tell_object(me,"因為錯誤的戰術而使你無法使用這種劍法。\n");
          return 0;
	}
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "mar_short1"  : type = 1;  break;
			case "mar_short2"  : type = 2;  break;
			case "mar_short3"  : type = 3;  break;
			case "mar_short4"  : type = 4;  break;
			case "mar_short5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("mar_short"+(string)type));
	return type;
}

int query_need_fp()
{
	return 4;
}

int *types_effect = ({8, 6, 4, 2, 0, -2, -8, -12});

int query_victim_attack_type(object victim)
{
  object weapon1;
  string weapon_type;
  int type_ex;
  
  if (!(weapon1=victim->query("weapon1"))) {
    return 10; 
  }
  weapon_type = weapon1->query("type");
  switch (weapon_type) {
    case "unarmed" :
      type_ex = 0;
      break;
    case "dagger" :
      type_ex = 1;
      break;
    case "shortblade" :
      type_ex = 2;
      break;
    case "chain" :
      type_ex = 3;
      break;
    case "blunt" :
      type_ex = 4;
      break;
    case "polearm" :
      type_ex = 6;
      break;
    case "whip" :
      type_ex = 7;
      break;                  
    default :
      type_ex = 5;                                                 
  }
  return types_effect[type_ex];
}
string *attack_msg = ({
"沈吟道：『揚□兮拊鼓，疏緩節兮安歌，陳竽瑟兮浩倡』。一振%s，使出首式『東皇太一』，劍法開闔有度刺向%s",
"『叱』地一聲大喝，心中存想：『龍駕兮帝服，聊翱遊兮周章～雲中君～』，意隨劍發，%s劍氣直射%s",
"劍式遊走，如同『湘君』飛龍翩翩過石瀨，%s幻出點點金星射向%s",
"使出一招『大司命』，只見%s劍光飛逝，一紫一青兩道長虹貫入%s",
"緊握%s，劍招若滔滔江水般紛呈不絕，惡狠狠地攻向%s",
"默唸：『風颯颯兮木簫蕭，思公子兮徒離憂！』%s隨勢一鬆，如同綿綿思緒，織成一張劍網，攔向了%s",
"一式『國殤』。%s劍勢如狂風暴雨般，挾著天崩地裂之勢卷向%s",
"身形凝滯，右腕一轉%s，翻出一朵劍花，在□□秋風中緩緩地刺向%s",
"『少司命』一出，%s劍勢隱沒不見，倏地，一道金光破開雲際，劍已划向%s",
"一招『山鬼』前式，%s劍芒暴現，陰森的青芒吞吞吐吐伴著雷填雨冥直噬%s"
});

//han
//int *hits = ({ 35, 40, 45, 50, 55 });
//int *pens = ({ 15, 27, 35, 45, 50 });
//int *dams = ({ 8, 11, 14, 17, 20 });

//mar_short
int *hits = ({ 30, 35, 30, 45, 50 });
int *pens = ({ 10, 22, 30, 40, 45 });
int *dams = ({ 7, 9, 12, 14, 17 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
    int hit2;
      
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
        hit2 = (hits[type-1] + random((int)me->query("scholar_gonfu/mar_short"))/6)
                + query_victim_attack_type(victim); 
	return (hit2*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	int pene2;
    if( type < 1 || type > 5 ) return 0;
    if( (int)me->query("force_points") < query_need_fp() ) return -20;
    pene2=(pens[type-1]+random((int)me->query("scholar_gonfu/mar_short"))/6)
          +query_victim_attack_type(victim);
    return (pene2*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;
	int dam2;
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
       if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/mar_short", 3*type+random(2*type));
        lvl = (int)me->query("scholar_gonfu/mar_short");
        dam2=dams[type-1] + lvl/3 + query_victim_attack_type(victim)/2; 
        if (random(36)<2) special_attack(me,victim);
	return (dam2*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if (random(2)>0) {
	  return attack_msg[(type-1)]; }
        else {
          return attack_msg[(type+4)]; }
}
