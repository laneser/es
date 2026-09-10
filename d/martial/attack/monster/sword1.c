// kitgonfu.c
// This is a attack skill that is only available for wizards.

varargs int can_use(object me, object victim, object weapon)
{
		int type;
		string last;
        if( !weapon||(string)weapon->query("type")!="longblade" ) return 0;
        if( last = (string)me->query_temp("last_attack_skill") )
        	switch( last ) {
        	  case "kitgonfu1"  : type = 1;  break;
        	  case "kitgonfu2"  : type = 2;  break;
        	  case "kitgonfu3"  : type = 3;  break;
        	  case "kitgonfu4"  : type = 4;  break;
        	  case "kitgonfu5"  : type = 5;  break;
        	  case "kitgonfu6"  : type = 6;  break;
        	  case "kitgonfu7"  : type = 7;  break;
        	  case "kitgonfu8"  : type = 8;  break;
        	  case "kitgonfu9"  : type = 9;  break;
        	  case "kitgonfu10" : type = 10; break;
        	  case "kitgonfu11" : type = 11; break;
        	  case "kitgonfu12" : type = 12; break;
        	  case "kitgonfu13" : type = 13; break;
        	  case "kitgonfu14" : type = 14; break;
        	  case "kitgonfu15" : type = 15; break;
        	  case "kitgonfu16" : type = 16; break;
        	  case "kitgonfu17" : type = 17; break;
        		default         : type = 0;  break;
        	}
        if( type > 0 && type < 17 && random(type+100) > type ) type++;
        else type = 1;
        me->set_temp("last_attack_skill", ("kitgonfu"+type));
        return type;
}

int query_need_fp()
{
	return 0;
}

string *attack_msg = ({
"施展屠狼劍法起手式『在水一方』，雙目脈脈含情，%s緩緩刺向%s",
"輕輕對你一笑，手中%s一招『清揚婉兮』，向%s擊去",
"窈窕的身形向左一閃，%s交至左手，一掌『輕羅小扇』，向%s輕輕拍去",
"深情的看了你一眼，施展屠狼劍法中『青梅竹馬』一招，%s擊向%s",
"害羞的低下了頭，使出『含羞帶怯』一招，%s向%s刺去",
"幽幽的嘆了一口氣，使出『六神無主』一式，%s有氣無力地攻向%s",
"將劍身不住的抖動，射出『佳期如夢』，%s一團劍花向%s飄去",
"拂去臉上的髮絲，施展『語笑嫣然』一招，%s劍走輕靈向%s刺去",
"突然反身出劍，%s一劍『回眸一笑』，擊向%s",
"劍交左手，以左手施展屠狼劍法之『狼心狗肺』一招，%s擊穿%s",
"舞出一片劍幕，大喝一聲哪裡逃!!!，%s猛然地劈向%s",
"冷冷的看著你，施展屠狼劍法中『死有餘辜』一式，%s快速向%s砍去",
"大笑一聲，劈出『窮途末路』，%s向%s猛然擊去",
"縱身一躍%s刺出『除惡務盡』一招，以雷霆萬鈞之勢攻向%s",
"%s一道青芒自劍鋒中竄出，一招『雨過天青』，幾點劍芒向%s射去",
"左手捏成劍訣，右手劍鋒幻化成千百點寒星，『柔情似水』一式刺出，%s迅速刺穿了%s",
"施展屠狼劍法中最後一招『萬狼歸宗』，%s萬道劍光向%s猛然擊去",
});

int *hits = ({ 20, 28, 29, 30, 31, 32, 33, 34, 35, 50, 51, 53, 54, 55, 57, 58, 60 });
int *penes = ({ 16, 18, 19, 20, 11, 12, 13, 14, 15, 10, 11, 13, 14, 15, 17, 18, 20 });
int *dams = ({ 0, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9 });

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return hits[type-1];
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -50;
        return penes[type-1];
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
		if( (int)me->query("force_points") < query_need_fp() ) return -5;
        me->add("force_points", -query_need_fp());
        return dams[type-1];
}

varargs string query_attack_msg(object me, object victim, int type)
{
		if( type < 1 || type > 17 ) return 0;
        return attack_msg[(type-1)];
}
