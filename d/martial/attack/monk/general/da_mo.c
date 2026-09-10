// 少林寺武功「達摩棍法」
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 1+random(2);
}

varargs int can_use(object me, object victim, object weapon)
{
        // 確定所使用武器是否正確
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
            return 0;                
        return 1;
}

string *attack_msg = ({
        "兩腳起跳，%s向%s右側猛劈下來，使出『鐵牛耕地』",
        "使出達摩棍法中一招『夜叉通天』，%s向前撩打，打向%s",
        "%s使出『雲飛當頂』，捲起飛沙走石，斜刺%s",
        "%s卷著一陣勁風，『舞花搗棍』攻向%s",
        "右腳不落地，%s由下向右繞至左側橫刺%s，乃是『流星趕月』",
        "%s『猿猴戲星』、『回頭望月』二式，快速無比擊向%s",
        "身形向右方一閃，%s一招『夜叉穿窗』刺向%s",
        "長嘯一聲，%s使出『火駒奔川』，擊向%s",
        "將%s由前向後絞，突然向左劈打，一招『猛虎藏威』，攻向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/da-mo");
	lvl = 8 + lvl/5;
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	return (6*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/da-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/da-mo", lvl/2+10);
	return (3*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手時顯得內力不足";
        return attack_msg[random(9)];
}
