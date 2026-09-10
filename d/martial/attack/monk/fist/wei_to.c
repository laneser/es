// wei-to.c
// This is a attack skill that is only available for monk.
inherit "/d/martial/attack/modify";
int query_need_fp()
{
       return 3;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
"%s『滄海桑田』『海枯石爛』拍向%s",
"%s欺身向前，左掌劈出『空谷迴音』，直取%s",
"%s身形一晃，右掌『無求乃樂』往%s一擊",
"%s縱身一躍，一記『當頭棒喝』往%s連劈三下",
"%s左掌右拳，『回頭是岸』攻向%s",
"%s左拳虛晃，右掌趁機打出『雨過天晴』向%s",
"%s凝神使出『懸崖勒馬』右手向%s揮出",
"%s左手護額，右手強襲%s，一招『連環絕手』打出",
"%s右手如狂風暴雨，一招『逆浪強襲』，砍向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (54*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (32*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	me->add("force_points", -query_need_fp());
        return ((13+random(8))*monk_modify(victim)/100); 
}

varargs string query_attack_msg(object me, object victim, int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手時顯得內力不足";
        return attack_msg[random(9)];
} 
