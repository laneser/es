// 少林寺武功「猴拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{
         return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式戰鬥訊息
string *attack_msg = ({
        "%s使出『猿猴出洞』雙拳向%s橫抓",
        "%s左轉回身使出一招『小猴溜陣』斜身抓向%s",
        "%s雙手如飛，快速向%s一抓",
        "%s身形狂轉，突然擊出一招『猿猴崩天』撲向%s",
        "%s身形斜偏，隨即一招『猿猴下山』，打向%s",
        "%s抓抓猴腮，一招『靈猴轉圈』，攻向%s",
        "%s縱身跳起，『鑽上九宵』迅速湯向%s",
        "%s一聲輕笑，使出『倒踢金爪』，翻身踢向%s",
        "%s身形一低直攻下盤，使出『猴子偷桃』，抓向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (int)me->query("force_points")<query_need_fp() ) return -5;    
        return (40*monk_modify(victim)/100);  
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points")< query_need_fp() ) return -5;
        return (20*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{       
        if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        return ((10+random(4))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手時顯得內力不足";
        return attack_msg[random(9)];
}
