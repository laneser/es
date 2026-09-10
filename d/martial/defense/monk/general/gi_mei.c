// 少林寺武功「寂滅身法」

int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/gi-mei")) ) return 0;
	return 1;
}

string *defense_msg = ({
        "%s腳踏飛星，快速的連退七步",
        "%s使出『寂滅為樂』，身形突然變的不清楚", 
        "%s雙掌合十，身體像陀螺般的不停旋轉",
        "%s身體順勢向上拔高",
        "%s身體東旋西轉，南奔北跳",
        "%s念起『心如虛空，不著空見』身形快速的向左飛去",
        "%s雙足飄移，身形難以捉摸",
        "%s閃向一邊",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/gi-mei");
        me->add("gonfus_exp/gi-mei", lvl+7);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5 + random(lvl/2); 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return  0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	return 3;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"但遊走時顯得內力不足";
        return defense_msg[random(8)];
}
