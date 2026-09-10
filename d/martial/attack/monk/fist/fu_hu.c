// 少林寺武功「伏虎拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{
         return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式戰鬥訊息
string *attack_msg = ({
        "%s凝氣於臂使出『並步雙砸拳』雙拳向%s揮出",
        "%s左轉回身使出一招『黑虎奔川』，右手砍向%s",
        "%s連續兩招虛掌，突然雙手成虎爪攻向%s",
        "%s身形狂轉，突然擊向%s，一招『推倒牆』使出",
        "%s身形斜偏閃讓，隨即一招『小虎抱月』，打向%s",
        "%s抽拳切掌左推右捺，一招『餓虎吞羊』，由四面八方攻向%s",
        "%s縱身飛起，『黑虎彈爪』、『銀爪劃瓶』連環砍出，劈向%s",
        "%s一聲虎嘯，使出『猛虎跳澗』，翻身劈擊%s",
        "%s身形一變，騰身而起使出『猛虎抖威』，一連三腿踢向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (int)me->query("force_points")<query_need_fp() ) return -5;    
        return (40*monk_modify(victim)/100) ;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points")< query_need_fp() ) return -5;
        return (30*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        return ((11+random(7))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手時顯得內力不足";
        return attack_msg[random(9)];
}
