// 少林寺武功「伏魔棍法」
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
                    return 0;
	return 1;
}

string *attack_msg = ({
        "踏上一步，%s向%s直劈下來，勁勢十分強勁",
        "使出伏魔棍法中一招『諸惡莫做』，%s自左而右，橫掃%s",
        "%s一連三棍，捲起飛沙走石，撲向%s",
        "左手握拳，右手的%s卷著一陣勁風，攻向%s",
        "雙腿右轉寒雞步，%s使出一招『一夫當關』，劈向%s",
        "%s如萬鈞雷霆，連續攻出『龍飛鳳舞』、『風狂雨驟』二式，擊向%s",
        "身形向右方一閃，%s不退反進，快速無比的刺向%s",
        "大喝一聲，%s使出伏魔棍法的『如影隨形』，擊向%s",
        "將%s快速旋轉，但見滿天棍影，突然一招『力挽狂瀾』，出其不意的攻向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + lvl/2 + random(lvl/4);
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + random(lvl);
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/fu-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/fu-mo", lvl/2+3);
	return (4*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手時顯得內力不足";
        return attack_msg[random(9)];
}
