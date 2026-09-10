// 武功「醉拳」 part2
// angel
// Jun 4 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{ 
    return 4;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type,i;
	string last;
        if( weapon ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "gonfu1"  : type = 1;  break;
        	  case "gonfu2"  : type = 2;  break;
        	  case "gonfu3"  : type = 3;  break;
        	  case "gonfu4"  : type = 4;  break;
        	  case "gonfu5"  : type = 5;  break;
        	  case "gonfu6"  : type = 6;  break;
        	  case "gonfu7"  : type = 7;  break;
        	  case "gonfu8"  : type = 8;  break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 8 && random(8) > 2 ) {type++;}
        else {type =1+random(8);}
        me->set_temp("last_attack_skill", ("gonfu"+type));
        return type;
}

// 各式戰鬥訊息
string *attack_msg = ({

        "%s輕輕一笑，使出『何仙姑，彈腰獻酒醉湯步』腳步飄移，攻向%s", 
        "%s一拐一拐，突然一招『鐵柺李，旋肘膝撞醉還真』打向%s",
        "%s一招『韓湘子，擒腕擊胸醉吹簫』擊向%s，而後做持蕭狀，甚為灑脫",
        "%s使出『藍采和，單提敬酒攔腰破』氣勢恢宏，擊向%s",
        "%s身形東歪西倒，一招『漢鍾離，醉步報□窩心頂』撞向%s",
        "%s『張果老，醉酒拋杯踢連環』一連三腿踢向%s",
        "%s單腳獨立，一記『曹國舅，仙人敬酒銷喉扣』雙手飛速扣向%s",
        "%s大喝一聲『呂洞賓，醉酒提壺力千均』雙拳雷霆萬鈞攻向%s",
                     });



int *hits = ({ 65, 78, 60, 76, 67, 75, 70, 75 });
int *dams = ({ 14, 16, 18, 20, 23, 25, 28, 30 });



varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() ) return -5; 
        return   (hits[type-1]*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{

        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() ) return -5; 
        return ((30 + random(11))*monk_modify(victim)/100) ;

}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
       if( (type<1||type>8) ) return 0;
       if( (int)me->query("force_points") < query_need_fp() )	return -5; 
       me->add("force_points", -query_need_fp());
       return (dams[type-1]*monk_modify(victim)/100); 
}

varargs string query_attack_msg(object me, object victim, int type)
{
        if( (type<1||type>8) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(8)]+"但是出手時顯得內力不足";
        return attack_msg[random(8)];
}
